------------------JDBC 23:12:00-------- Java Database Connectivity
Database can be - Rdbms (oracle, mysql, sql server)
                - NoSql (mongodb, cassandra, firebase)

We use one driver to connect to different databases
we have 4 choices 
1. Native Driver (ODBC bridge) used for MS access
2. Native api
3. Pure java drivers
4. Network Protocol Driver

Steps to connect to Database (Like calling)
1. Import package  (phone)  
2. Load and Register the driver (need network) 
3. Establish the Connection (dial the call)
4. Cerate the statement (what we have to talk)
5. Execute the query (speak)
6. Process Result (get response)
7. Close (close phone)

1. java.sql.*
2. com.mysql.jdbc.Driver  (Download jar from mysql connector jar)
    forName("com.mysql.jdbc.Driver");   Get from https://mvnrepository.com/artifact/mysql/mysql-connector-java

    and add this in pom.xml
    <dependency>
        <groupId>mysql</groupId>
        <artifactId>mysql-connector-java</artifactId>
        <version>8.0.33</version>
    </dependency>

3. Connection
4. 4 type (statement, prepared statement, callable statement)

-------------------------Sample code-
import java.sql.*
main(){
    Class.forName("com.mysql.jdbc.Driver");
    Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/kalyan","root","root");  //getConnection returns obj of connection (url, username, password)

    Statement stmt = con.createStatement();

    ResultSet rs = stmt.executeQuery("select * from student");

    while(rs.next()){
        System.out.println(rs.getInt(1)+" "+rs.getString(2)+" "+rs.getString(3));
    }
}

DDL - create structure  stmt.executeUpdate()
    stmt.executeUpdate("CREATE TABLE students (id INT, name VARCHAR(50))");

DML - Insert/delete vlaue  stmt.executeUpdate()
    stmt.executeUpdate("INSERT INTO students (id, name) VALUES (1, 'John Doe')");

DQL - Fire query for fetching vlaue.  stmt.executeQuery
    stmt.executeQuery("SELECT * FROM students");





in kalyan project-> created fileName Sqljdbc.java

in pom.xml of project i added->
		<dependency>
			<groupId>mysql</groupId>
			<artifactId>mysql-connector-java</artifactId>
			<version>8.0.31</version>  
		</dependency>


public static void main(String[] args) {
         String query = "CREATE TABLE Employee (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255));";
         try {
             Class.forName("com.mysql.cj.jdbc.Driver");
             Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/kalyan", "root", "Root@123");  //here kalyan is database name
             Statement stmt = con.createStatement();
  
             stmt.executeUpdate(query); // Create the table
  
             //insert 2 values
             String insertQuery = "INSERT INTO Employee (name) VALUES ('Kalyan'), ('Gungun')";
             stmt.executeUpdate(insertQuery);

             String selectQuery = "SELECT * FROM Employee"; 
             ResultSet rs = stmt.executeQuery(selectQuery); // For querying data, resultset store the chunk of data.
 
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


