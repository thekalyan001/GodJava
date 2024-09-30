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
2. com.mysql.jdbc.Driver  (Download jar from mysql connector)
    forName("com.mysql.jdbc.Driver");
3. Connection
4. 4 type (statement, prepared statement, callable statement)
