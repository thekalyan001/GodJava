package com.mishra.kalyan;

import java.sql.*;

class Student {
    int id;
    String name;
}

class StudentDAO {

    // connection
    Connection con = null;

    public void connect() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/kalyan", "root", "Root@123");

        } catch (Exception ex) {
            System.out.println(ex);
        }

    }

    public Student getStudent(int id) throws SQLException { // return type is class
        Student s = new Student();
        s.id = id;
        // fetch name from db name kalyan
        connect();
        String query = "select name from employee where id=" + id;
        Statement stmt = con.createStatement();
        ResultSet rs = stmt.executeQuery(query);

        if (rs.next()) { // Check if ResultSet has data
            s.name = rs.getString("name");
        } else {
            System.out.println("\nID not found. Please check your query.");
            s.name = "Unknown";
        }

        return s;
    }

    // add student, for adding always goto prepared statement
    public void addStudent(Student s) {

        String query = "insert into employee values(?, ?)";
        PreparedStatement pst;
        try {
            pst = con.prepareStatement(query);
            pst.setInt(1, s.id);
            pst.setString(2, s.name);
            pst.executeUpdate();
        } catch (Exception e) {  //generalize exception
             System.out.println(e);
        }

    }

}

public class JdbcDaoDemo {
    public static void main(String[] args) throws SQLException {
        StudentDAO dao = new StudentDAO();

        // fetch student
        //Student s = dao.getStudent(12);
        //System.out.println(s.id + " " + s.name);


        // add student
        Student s2 = new Student();
        s2.id = 6;
        s2.name = "Archana";
        dao.connect();
        dao.addStudent(s2);
    }
}
