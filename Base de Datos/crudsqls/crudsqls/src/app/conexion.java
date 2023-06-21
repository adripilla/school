package app;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class conexion {
    
    public static Connection getCon(){
        String connectionUrl =
                "jdbc:sqlserver://localhost:1433;"
                        + "database=escuelas;"
                        + "user=sa;"
                        + "password=123;"
                        + "TrustServerCertificate=True;"
                ;

        try {
            // Code here.
            Connection con = DriverManager.getConnection(connectionUrl);
            return con;
        }
        // Handle any errors that may have occurred.
        catch (SQLException e) {
            System.out.println(e.toString());
            return null;
        }
    }
}