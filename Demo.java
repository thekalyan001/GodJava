/*
 *  1. Import package   ->java.sql.*
    2. Load and Register the driver -> forMysql com.mysql.jdbc.Driver  Download from https://mvnrepository.com/artifact/mysql/mysql-connector-java
    3. Establish the Connection
    4. Cerate the statement
    5. Execute the query 
    6. Process Result 
    7. Close
 */

import java.sql.*;

public class Demo {
    public static void main(String[] args) {
        String query = "CREATE TABLE Employee (id INT AUTO_INCREMENT PRIMARY KEY, amee VARCHAR(255));";
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/kalyan", "root", "Root@123");
            Statement stmt = con.createStatement();

            // Create the table
            stmt.executeUpdate(query); 

            // For querying data
            String selectQuery = "SELECT * FROM Employee"; 
            ResultSet rs = stmt.executeQuery(selectQuery);

            while (rs.next()) {
                System.out.println(rs.getInt("id") + " " + rs.getString("amee"));
            }

            rs.close();
            stmt.close();
            con.close();
        } catch (Exception e) {
            e.printStackTrace(); // Print exception details for debugging
        }
    }
}
 