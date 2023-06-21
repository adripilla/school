/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package codigo;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.util.concurrent.Executor;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author rodri
 */
public class acciones {

    Connection con = conexion.getCon();
    PreparedStatement ps = null;

    public void insert(Object[] fila) {
        try {
            if (verificar() == 0) {
                con.setAutoCommit(false);
                ps = con.prepareStatement("insert into tabla(matricula,nombre,edad,tele) values (?,?,?,?)");
                ps.setString(1, fila[0] + "");
                ps.setString(2, fila[1] + "");
                ps.setString(3, fila[2] + "");
                ps.setString(4, fila[3] + "");
                ps.executeUpdate();
            } else {
                JOptionPane.showMessageDialog(null, "hay una transaccion en curso" + con.getNetworkTimeout());

            }
        } catch (SQLException ex) {
            Logger.getLogger(acciones.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void confirmar() {
        try {
            con.commit();
        } catch (SQLException ex) {
            Logger.getLogger(acciones.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public void cancelar() {
        try {
            con.rollback();
        } catch (SQLException ex) {
            Logger.getLogger(acciones.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public Object[] cargarTabla(int filas) {
        int vueltas = 0;
        try {
            if (verificar() == 0) {
                con.setAutoCommit(false);
                ps = con.prepareStatement("select matricula, nombre,edad,tele from tabla");
                ResultSet rs = ps.executeQuery();
                if (con.getNetworkTimeout() > 1000) {
                    con.rollback();
                }
                ResultSetMetaData rsmd = rs.getMetaData();
                int col = rsmd.getColumnCount();
                while (rs.next()) {
                    Object[] fila = new Object[col];
                    for (int i = 0; i < col; i++) {
                        fila[i] = rs.getObject(i + 1);
                    }
                    if (filas == vueltas) {
                        con.commit();
                        return fila;
                    }
                    vueltas++;
                }
            }
        } catch (SQLException e) {
            try {
                con.rollback();
            } catch (SQLException ex) {
                Logger.getLogger(acciones.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("error");
        }
        return null;
    }

    public int verificar() {
        PreparedStatement pss;
        String cadena = "CREATE TABLE #OpenTranStatus (ActiveTransaction VARCHAR(25),Details sql_variant)"
                + " INSERT INTO #OpenTranStatus EXEC ('DBCC OPENTRAN WITH TABLERESULTS, NO_INFOMSGS');"
                + "SELECT Count(*) FROM #OpenTranStatus;";
        try {
            pss = con.prepareStatement(cadena);
            ResultSet rs = pss.executeQuery();
            ResultSetMetaData rsmd = rs.getMetaData();
            rsmd = rs.getMetaData();
            if (rs.next()) {
                return rs.getInt(1);
            }
        } catch (SQLException ex) {
            Logger.getLogger(acciones.class.getName()).log(Level.SEVERE, null, ex);
        }
        return 0;

    }

    public int rows() {
        ResultSet rs;
        ResultSetMetaData rsmd;
        int col;
        int vueltas = 0;
        try {
            ps = con.prepareStatement("select count(matricula) from tabla");
            rs = ps.executeQuery();
            rsmd = rs.getMetaData();
            if (rs.next()) {
                return rs.getInt(1);
            }
        } catch (SQLException e) {
            try {
                con.rollback();
            } catch (SQLException ex) {
                Logger.getLogger(acciones.class.getName()).log(Level.SEVERE, null, ex);
            }
            System.out.println("error");
        }
        return 0;
    }
}
