import javax.swing.*;
import javax.swing.text.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import java.util.concurrent.locks.*;

public class CambioFuente extends JFrame {

    
    /*
            quita o has lo mas pequeña que se pueda la ventana del output por que sale un error pero no afecta 
            solo para que no vea que hay errores
    
    */
    private JTextPane textPane;
    private Thread[] fontThreads;
    private String[] targetWords = {"C20130864", "daniel", "marin"};
    private Font[] fonts = {new Font("Arial", Font.BOLD, 14),
        new Font("Times New Roman", Font.ITALIC, 14),
        new Font("Courier New", Font.PLAIN, 18)};
    private ReadWriteLock docLock = new ReentrantReadWriteLock();

    public CambioFuente() {
        //creacion del frame y componentes
        setTitle("Cambio de Fuente");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        textPane = new JTextPane();
        textPane.setFont(new Font("Arial", Font.PLAIN, 14));
        add(new JScrollPane(textPane));

        fontThreads = new Thread[targetWords.length];

        textPane.getDocument().addDocumentListener(new DocumentListener() {

        //detiene cualquier hilo que haya por si llegase a haber
            private void stopAllFontThreads() {
                for (Thread thread : fontThreads) {
                    if (thread != null && thread.isAlive()) {
                        thread.interrupt();
                    }
                }
            }

            //al teclear detiene los hilos en ejecucion y los actualiza la informacion
            @Override
            public void insertUpdate(DocumentEvent e) {
                stopAllFontThreads();
                updateFont();
            }

            //lo mismo pero por si borras
            @Override
            public void removeUpdate(DocumentEvent e) {
                stopAllFontThreads();
                updateFont();
            }

            //actualizar
            @Override
            public void changedUpdate(DocumentEvent e) {
                updateFont();
            }

            //actualizar fuente 
            private void updateFont() {
                String text = textPane.getText();
                //ciclo que recorre las 3 palabras que buscas
                for (int i = 0; i < targetWords.length; i++) {
                    String word = targetWords[i];
                    Font font = fonts[i];
                    int index = -1;

                    //compara la palabra que buscas con las palabras que escribiste
                    while ((index = text.indexOf(word, index + 1)) >= 0) {
                        stopFontThread(i); // Detener el hilo existente, si hay alguno
                        startFontThread(i, index);//inicia el hilo de la palabra en la posicion i y lo aplica en la palabra en posicion index
                    }
                }
            }

        });
    }

    public void startFontThread(int index, int startIndex) {
        //crea un hilo en el arreglo de hilos con el codigo siguiente
        fontThreads[index] = new Thread(() -> {
            Font newFont = fonts[index];

            while (!Thread.currentThread().isInterrupted()) {
                try {
                    docLock.writeLock().lockInterruptibly(); // Adquirir el bloqueo de escritura permitiendo interrupciones
                    //cambio de fuente
                    StyledDocument doc = textPane.getStyledDocument();
                    Style style = doc.addStyle("changedFont" + index, null);
                    StyleConstants.setFontFamily(style, newFont.getFamily());
                    StyleConstants.setFontSize(style, newFont.getSize());
                    StyleConstants.setBold(style, newFont.isBold());
                    StyleConstants.setItalic(style, newFont.isItalic());

                    int start = startIndex;
                    int length = targetWords[index].length();
                    doc.setCharacterAttributes(start, length, doc.getStyle("changedFont" + index), true);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                } finally {
                    docLock.writeLock().unlock(); // Liberar el bloqueo de escritura
                }

                try {
                    Thread.sleep(1000); // Cambia la fuente cada 1 segundo
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    break;
                }
            }
        });

        fontThreads[index].start();//pone en ejecucion el hilo
    }

    public void stopFontThread(int index) {
        //detener hilos
        if (fontThreads[index] != null && fontThreads[index].isAlive()) {
            fontThreads[index].interrupt();
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            CambioFuente cambioFuente = new CambioFuente();
            cambioFuente.setVisible(true);
        });
    }
}
