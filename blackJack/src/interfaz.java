
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
/**
 *
 * @author rodri
 */
public class interfaz extends javax.swing.JFrame {

    int njugadores;
    int cartas1 = 2;
    int cartas2 = 2;
    int cartas3 = 2;
    int cartas4 = 2;
    int total1 = 0;
    int total2 = 0;
    int total3 = 0;
    int total4 = 0;
    boolean[][] maso = new boolean[4][13];
    boolean[] finalizar = {false, false, true, true};
    int nm = 52;
    int nx = 0;

    JLabel j1c1 = new JLabel("");
    JLabel j1c2 = new JLabel("");
    JLabel j2c1 = new JLabel("");
    JLabel j2c2 = new JLabel("");
    JLabel j1c3 = new JLabel("");
    JLabel j2c3 = new JLabel("");
    JLabel j1c4 = new JLabel("");
    JLabel j2c4 = new JLabel("");
    JLabel j3c1 = new JLabel("");
    JLabel j3c2 = new JLabel("");
    JLabel j3c3 = new JLabel("");
    JLabel j3c4 = new JLabel("");
    JLabel j4c1 = new JLabel("");
    JLabel j4c2 = new JLabel("");
    JLabel j4c3 = new JLabel("");
    JLabel j4c4 = new JLabel("");
    JLabel j1c5 = new JLabel("");
    JLabel j2c5 = new JLabel("");
    JLabel j3c5 = new JLabel("");
    JLabel j4c5 = new JLabel("");
    JLabel marcadorj1 = new JLabel("");
    JLabel marcadorj2 = new JLabel("");
    JLabel marcadorj3 = new JLabel("");
    JLabel marcadorj4 = new JLabel("");
    JLabel contador1 = new JLabel("");
    JLabel contador2 = new JLabel("");
    JLabel contador3 = new JLabel("");
    JLabel contador4 = new JLabel("");
    JLabel v11 = new JLabel("");
    JLabel v12 = new JLabel("");
    JLabel v13 = new JLabel("");
    JLabel v14 = new JLabel("");

    public void llenar() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                maso[i][j] = true;
            }
        }
    }

    String obcar = "";

    public int probabilidad(int total) {
        total = 20 - total;
        int contador = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                if (maso[i][j] && j <= total) {
                    contador++;
                }
            }
        }
        return contador;
    }

    public void obtenerCarta() {
        int num = (int) Math.round(Math.random() * (12 - 0));
        int tipo = (int) Math.round(Math.random() * (3 - 0));
        String a[] = {"d", "c", "t", "p"};
        if (nm == 0) {
            System.out.println("no quedan cartas");
        }
        if (!maso[tipo][num]) {
            obtenerCarta();
        }
        if (maso[tipo][num]) {
            maso[tipo][num] = false;
            nm--;
            if (num >= 10) {
                nx = 10;
            } else {
                if (num == 0) {
                    int reply = JOptionPane.showConfirmDialog(null, "¿quieres que el as valga 11?", "as", JOptionPane.YES_NO_OPTION);
                    if (reply == JOptionPane.YES_OPTION) {
                        nx = 11;
                    } else {
                        nx = 1;
                    }
                } else {
                    nx = num + 1;
                }
            }
            obcar = "" + (num + 1) + a[tipo] + "";
        }

    }

    public interfaz() {
        initComponents();
        marcadorj3.setVisible(false);
        marcadorj4.setVisible(false);
        contador3.setVisible(false);
        contador4.setVisible(false);
        v13.setVisible(false);
        v14.setVisible(false);

        this.jButton7.setVisible(false);
        this.jButton8.setVisible(false);
        this.jButton3.setVisible(false);
        this.jButton4.setVisible(false);
        this.jLabel3.setVisible(false);
        this.jLabel4.setVisible(false);

        int njugadores = Integer.parseInt(JOptionPane.showInputDialog("Numero de jugadores:"));
        llenar();
        this.obtenerCarta();
        String carta1j1 = obcar;
        total1 += nx;
        this.obtenerCarta();
        String carta1j2 = obcar;
        total2 += nx;
        this.obtenerCarta();
        String carta2j1 = obcar;
        total1 += nx;
        this.obtenerCarta();
        String carta2j2 = obcar;
        total2 += nx;

        if (njugadores == 3 || njugadores == 4) {
            total3 = 0;
            this.obtenerCarta();
            String carta1j3 = obcar;
            total3 += nx;
            this.obtenerCarta();
            String carta2j3 = obcar;
            total3 += nx;
            this.j3c1.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta1j3 + ".jpg"));
            this.j3c2.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta2j3 + ".jpg"));
            j3c1.setBounds(300, 50, 125, 180);
            j3c2.setBounds(310, 75 + 50, 125, 180);
            marcadorj3.setVisible(true);
            contador3.setVisible(true);
            this.jButton7.setVisible(true);
            this.jButton3.setVisible(true);
            this.jLabel3.setVisible(true);
            v13.setVisible(true);
            finalizar[2] = false;
        }
        if (njugadores == 4) {
            total4 = 0;
            this.obtenerCarta();
            String carta2j4 = obcar;
            total4 += nx;
            this.obtenerCarta();
            String carta1j4 = obcar;
            total4 += nx;
            this.j4c1.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta1j4 + ".jpg"));
            this.j4c2.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta2j4 + ".jpg"));
            j4c1.setBounds(450, 0 + 50, 125, 180);
            j4c2.setBounds(460, 75 + 50, 125, 180);
            marcadorj4.setVisible(true);
            contador4.setVisible(true);
            this.jButton8.setVisible(true);
            this.jButton4.setVisible(true);
            this.jLabel4.setVisible(true);
            v14.setVisible(true);
            finalizar[3] = false;

        }

        this.j1c1.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta1j1 + ".jpg"));
        this.j1c2.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta2j1 + ".jpg"));
        this.j2c1.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta1j2 + ".jpg"));
        this.j2c2.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta2j2 + ".jpg"));
        j1c1.setBounds(1, 0 + 50, 125, 180);
        j1c2.setBounds(10, 75 + 50, 125, 180);
        j2c1.setBounds(150, 0 + 50, 125, 180);
        j2c2.setBounds(160, 75 + 50, 125, 180);

        marcadorj1.setBounds(10, 500, 100, 80);
        marcadorj2.setBounds(160, 500, 100, 80);
        marcadorj3.setBounds(310, 500, 100, 80);
        marcadorj4.setBounds(460, 500, 100, 80);
        marcador();
        contador1.setBounds(10, 580, 120, 80);
        contador2.setBounds(160, 580, 120, 80);
        contador3.setBounds(310, 580, 120, 80);
        contador4.setBounds(460, 580, 120, 80);

        v11.setBounds(10, 580 - 40, 120, 80);
        v12.setBounds(160, 580 - 40, 120, 80);
        v13.setBounds(310, 580 - 40, 120, 80);
        
        v14.setBounds(460, 580 - 40, 120, 80);

        add(j1c5);
        add(j2c5);
        add(j3c5);
        add(j4c5);
        add(j3c4);
        add(j3c3);
        add(j3c2);
        add(j3c1);
        add(j4c4);
        add(j4c3);
        add(j4c2);
        add(j4c1);
        add(j2c4);
        add(j1c4);
        add(j1c3);
        add(j2c3);
        add(j2c2);
        add(j1c2);
        add(j1c1);
        add(j2c1);
        add(marcadorj1);
        add(marcadorj2);
        add(marcadorj3);
        add(marcadorj4);
        add(contador1);
        add(contador2);
        add(contador3);
        add(contador4);
        add(v11);
        add(v12);
        add(v13);
        add(v14);
    }

    public int probabilidad21(int total) {
        total = 20 - total;
        int contador = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                if (total == 9 && maso[i][j] && j >= total ||total == 10 && maso[i][j] && j == 0) {
                    
                        contador++;
                }
                if (total != 9 && maso[i][j] && j == total && total != 10  ) {
                    contador++;
                }
            }
        }
        return contador;
    }

    public void marcador() {
        marcadorj1.setText("total j1:" + total1 + "");
        marcadorj2.setText("total j2:" + total2 + "");
        marcadorj3.setText("total j3:" + total3 + "");
        marcadorj4.setText("total j4:" + total4 + "");
        contador1.setText("probabilidad " + probabilidad(total1) + "/" + contar());
        contador2.setText("probabilidad " + probabilidad(total2) + "/" + contar());
        contador3.setText("probabilidad " + probabilidad(total3) + "/" + contar());
        contador4.setText("probabilidad " + probabilidad(total4) + "/" + contar());
        v11.setText("probabilidad 21 " + probabilidad21(total1) + "/" + contar());
        v12.setText("probabilidad 21 " + probabilidad21(total2) + "/" + contar());
        v13.setText("probabilidad 21 " + probabilidad21(total3) + "/" + contar());
        v14.setText("probabilidad 21 " + probabilidad21(total4) + "/" + contar());

    }

    public boolean paso(int x) {
        if (x <= 20) {
            return true;
        } else {
            return false;
        }
    }

    public void fin() {
        if (finalizar[0] && finalizar[1] && finalizar[2] && finalizar[3]) {

            total3 = 21 - total3;
            total4 = 21 - total4;
            total1 = 21 - total1;
            total2 = 21 - total2;

            if (total3 == 21 && total4 == 21) {
                if (total1 < total2 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 1 gana.....");
                }
                if (total2 < total1 && total2 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 2 gana.....");
                }
                if (total2 == total1 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "empate.......");
                }
                if (total2 < 0 && total1 < 0) {
                    JOptionPane.showMessageDialog(null, "la casa gana.........");
                }
            }
            if (total3 != 21 && total4 == 21) {

                if (total1 < total2 && total1 < total3 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 1 gana____________");
                }
                if (total2 < total1 && total2 < total3 && total2 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 2 gana_____________");
                }
                if (total3 < total1 && total3 < total2 && total3 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 3 gana_______________");
                }
                if (total1 == total2 && total1 != total3 && total3 != 0 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "empate J1 y J2________________");
                }
                if (total1 == total3 && total1 != total2 && total2 != 0 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "empate J1 y J3_________________");
                }
                if (total2 == total3 && total2 != total1 && total1 != 0 && total2 >= 0) {
                    JOptionPane.showMessageDialog(null, "empate J2 y J3________________--");
                }
                if (total1 == total3 && total1 == total2 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "empate triple_________________");
                }
                if (total2 < 0 && total1 < 0 && total3 < 0) {
                    JOptionPane.showMessageDialog(null, "la casa gana_________________");
                }
            }
            if (total3 != 21 && total4 != 21) {
                if (total1 < total2 && total1 < total3 && total1 < total4 && total1 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 1 gana!!!!!!!!!!");
                }
                if (total2 < total1 && total2 < total3 && total2 < total4 && total2 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 2 gana!!!!!!!!!");
                }
                if (total3 < total1 && total3 < total2 && total3 < total4 && total3 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 3 gana!!!!!!!!!!");
                }

                if (total4 < total1 && total4 < total2 && total4 < total3 && total4 >= 0) {
                    JOptionPane.showMessageDialog(null, "jugador 4 gana!!!!!!!!!");
                }
                if (total1 == total2 && total1 != total3 && total1 != total4 && total1 >= 0 && total3 != 0 && total4 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j1 y j2!!!!!!!!!");
                }
                if (total1 != total2 && total1 == total3 && total1 != total4 && total1 >= 0 && total2 != 0 && total4 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j1 y j3!!!!!!!!!!!");
                }
                if (total1 != total2 && total1 != total3 && total1 == total4 && total1 >= 0 && total3 != 0 && total2 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j1 y j4!!!!!!!!!!");
                }
                if (total2 != total1 && total2 == total3 && total2 != total4 && total2 >= 0 && total1 != 0 && total4 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j2 y j3!!!!!!!!!!");
                }
                if (total2 != total1 && total2 != total3 && total2 == total4 && total2 >= 0 && total1 != 0 && total3 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j2 y j4!!!!!!!!!");
                }
                if (total3 != total1 && total3 != total2 && total3 == total4 && total3 >= 0 && total1 != 0 && total2 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j3 y j4!!!!!!!!!!!");
                }
                if (total1 == total2 && total1 == total3 && total1 != total4 && total1 >= 0 && total4 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j1,j2 y j3!!!!!!!!!!");
                }
                if (total1 == total2 && total1 != total3 && total1 == total4 && total1 >= 0 && total3 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j1,j2 y j4!!!!!!!!!!");
                }
                if (total1 != total2 && total1 == total3 && total1 == total4 && total1 >= 0 && total2 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j1,j3 y j4!!!!!!!");
                }
                if (total2 != total1 && total2 == total3 && total2 == total4 && total2 >= 0 && total1 != 0) {
                    JOptionPane.showMessageDialog(null, "empate j2,j3 y j4!!!!!!!!!");
                }
                if (total2 == total1 && total2 == total3 && total2 == total4 && total2 >= 0) {
                    JOptionPane.showMessageDialog(null, "empate!!!!!!!");
                }
                if (total2 < 0 && total1 < 0 && total3 < 0 && total4 < 0) {
                    JOptionPane.showMessageDialog(null, "la casa gana!!!!!!");
                }
            }
        }

    }

    public String contar() {
        int disp = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                if (maso[i][j]) {
                    disp++;
                }
            }
        }
        return disp + "";
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jButton7 = new javax.swing.JButton();
        jButton8 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jButton1.setText("pedir carta J1");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("pedir carta J2");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("pedir carta J3");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("pedir carta J4");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton5.setText("quedar");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton6.setText("quedar");
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });

        jButton7.setText("quedar");
        jButton7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton7ActionPerformed(evt);
            }
        });

        jButton8.setText("quedar");
        jButton8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton8ActionPerformed(evt);
            }
        });

        jLabel1.setText("jugador 1");

        jLabel2.setText("jugador 2");

        jLabel3.setText("jugador 3");

        jLabel4.setText("jugador 4");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(jButton5, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton1, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(52, 52, 52)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jButton2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(63, 63, 63)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jButton3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton7, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(55, 55, 55)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jButton4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton8, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(0, 373, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addComponent(jLabel1)
                .addGap(69, 69, 69)
                .addComponent(jLabel2)
                .addGap(112, 112, 112)
                .addComponent(jLabel3)
                .addGap(89, 89, 89)
                .addComponent(jLabel4)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(27, 27, 27)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 585, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1, javax.swing.GroupLayout.PREFERRED_SIZE, 29, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton2)
                    .addComponent(jButton3)
                    .addComponent(jButton4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton5)
                    .addComponent(jButton6)
                    .addComponent(jButton7)
                    .addComponent(jButton8))
                .addGap(15, 15, 15))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        // TODO add your handling code here:
        this.obtenerCarta();
        total1 += nx;
        String carta = obcar;
        if (cartas1 == 2) {
            this.j1c3.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j1c3.setBounds(20, 150 + 50, 125, 180);
        }
        if (cartas1 == 3) {
            this.j1c4.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j1c4.setBounds(30, 225 + 50, 125, 180);
        }
        if (cartas1 == 4) {
            this.j1c5.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j1c5.setBounds(40, 295 + 50, 125, 180);
        }
        cartas1++;
        marcador();
        this.jButton1.setEnabled(paso(total1));
        if (!paso(total1)) {
            finalizar[0] = true;
        }
        fin();
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        // TODO add your handling code here:
        this.obtenerCarta();
        total2 += nx;
        String carta = obcar;
        if (cartas2 == 2) {
            this.j2c3.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j2c3.setBounds(170, 150 + 50, 125, 180);
        }
        if (cartas2 == 3) {
            this.j2c4.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j2c4.setBounds(180, 225 + 50, 125, 180);
        }
        if (cartas2 == 4) {
            this.j2c5.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j2c5.setBounds(190, 295 + 50, 125, 180);
        }
        cartas2++;
        marcador();
        this.jButton2.setEnabled(paso(total2));
        if (!paso(total2)) {
            finalizar[1] = true;
        }
        fin();
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        // TODO add your handling code here:
        this.obtenerCarta();
        total3 += nx;
        String carta = obcar;
        if (cartas3 == 2) {
            this.j3c3.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j3c3.setBounds(320, 150 + 50, 125, 180);
        }
        if (cartas3 == 3) {
            this.j3c4.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j3c4.setBounds(330, 225 + 50, 125, 180);
        }
        if (cartas3 == 4) {
            this.j3c5.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j3c5.setBounds(340, 295 + 50, 125, 180);
        }
        cartas3++;
        marcador();
        this.jButton3.setEnabled(paso(total3));
        if (!paso(total3)) {
            finalizar[2] = true;
        }
        fin();
    }//GEN-LAST:event_jButton3ActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        // TODO add your handling code here:
        this.obtenerCarta();
        total4 += nx;
        String carta = obcar;
        if (cartas4 == 2) {
            this.j4c3.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j4c3.setBounds(470, 150 + 50, 125, 180);
        }
        if (cartas4 == 3) {
            this.j4c4.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j4c4.setBounds(480, 225 + 50, 125, 180);
        }
        if (cartas4 == 4) {
            this.j4c5.setIcon(new ImageIcon("C:\\Users\\rodri\\OneDrive\\Documentos\\NetBeansProjects\\blackJack\\img\\" + carta + ".jpg"));
            j4c5.setBounds(490, 295 + 50, 125, 180);
        }
        cartas4++;
        marcador();
        this.jButton4.setEnabled(paso(total4));
        if (!paso(total4)) {
            finalizar[3] = true;
        }
        fin();
    }//GEN-LAST:event_jButton4ActionPerformed

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        // TODO add your handling code here:
        this.jButton1.setEnabled(false);
        finalizar[0] = true;
        fin();
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton6ActionPerformed
        // TODO add your handling code here:
        this.jButton2.setEnabled(false);
        finalizar[1] = true;
        fin();
    }//GEN-LAST:event_jButton6ActionPerformed

    private void jButton7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton7ActionPerformed
        // TODO add your handling code here:
        this.jButton3.setEnabled(false);
        finalizar[2] = true;
        fin();
    }//GEN-LAST:event_jButton7ActionPerformed

    private void jButton8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton8ActionPerformed
        // TODO add your handling code here:
        this.jButton4.setEnabled(false);
        finalizar[3] = true;
        fin();
    }//GEN-LAST:event_jButton8ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(interfaz.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new interfaz().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JButton jButton7;
    private javax.swing.JButton jButton8;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    // End of variables declaration//GEN-END:variables
}
