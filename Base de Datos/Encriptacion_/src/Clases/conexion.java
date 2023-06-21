package Clases;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class conexion {

    public static Connection getCon() {
        String connectionUrl
                = "jdbc:sqlserver://localhost:1433;"
                + "database=cifrado;"
                + "user=sa;"
                + "password=123;"
                + "TrustServerCertificate=True;";
        try {
            Connection con = DriverManager.getConnection(connectionUrl);
            return con;
        } catch (SQLException e) {
            System.out.println(e.toString());
            return null;
        }
    }
}
