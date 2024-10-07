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

-------------------------Sample code----
import java.sql.*
main(){
    Class.forName("com.mysql.jdbc.Driver");  //forName is used to load the driver
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

7 step of JDBC.
/*
 *  1. Import package   ->java.sql.*
    2. Load and Register the driver -> forMysql com.mysql.jdbc.Driver  Download from https://mvnrepository.com/artifact/mysql/mysql-connector-java
    3. Establish the Connection
    4. Cerate the statement
    5. Execute the query 
    6. Process Result 
    7. Close
 */


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
                 System.out.println(rs.getInt("id") + " " + rs.getString("name"));
             }
 
             rs.close();
             stmt.close();
             con.close();
         } catch (Exception e) {
             e.printStackTrace(); // Print exception details for debugging
         }
     }


---------inserting values
for single values use statemnt
             Statement stmt = con.createStatement();
             String insertQuery = "INSERT INTO Employee (name) VALUES ('Kalyan'), ('Gungun')";
             stmt.executeUpdate(insertQuery);

to insert multiple values we should use Prepared statemnt 
    string name = "Kalyan";
    string id = "12";

    String query = "INSERT INTO Employee (name) VALUES (?,?)";
    PreparedStatement pstmt = con.prepareStatement(query);
    pstmt.setInt(1, id);
    pstmt.setString(2, name);
    pstmt.executeUpdate();




-----------Improtant 💡 Class.ForName to load the class  1:00:10:00
//class.forName() ka use hota h class load krwane ke liye
/*
 * whenever we create an obj so before it will load the class and while loading it will call static Block
 * and while creating object it will call instance block.
 */
public class Demo {
    public static void main(String[] args) {
        Pqr obj = new Pqr();
    }
}

class Pqr {
    static 
    {
        System.out.println("static block");
    }
    {
        System.out.println("in instance");
    }
}



--------load class only (it will call static block)
public static void main(String[] args) {
        try {
            Class.forName("Pqr");
        } catch (ClassNotFoundException e) { 
            e.printStackTrace();
        }
    }

--------------create instance also
public static void main(String[] args) throws InstantiationException, IllegalAccessException, ClassNotFoundException {
        Class.forName("Pqr").newInstance(); 
}


--so in JDBC we load class using DriverManager
DriverManager.RegisterDriver(new com.mysql.cj.jdbc.Driver())

this is same as 🏃🏻‍♂️
Class.forName("com.mysql.cj.jdbc.Driver");

why same?😏
bcoz if you ctrl+click on Driver and see it is calling static block and inside that static block
its calling java.sql.DriverManager.RegisterDriver(new Driver());

so directly we can call Class.forName("com.mysql.cj.jdbc.Driver"); and this will register the driver b calling it.



----------------------DAO (data access object) DAO design pattern. 1:00:15:00 -------
(It create layer and in case prolem change dao not whole software);

JdbcDaoDemo.java file me h code.







------------------SERVLET 🤡 (1:00:33:15)---------
How Servelet Works-----

Client send request to server and server send back the page to client-
what if page is not there and it will eb Build at Run time--?
so it goes to Helper Application called (Web container). in this Web container we have servelet is java file which take request from client on internet
and process the request and provide HTML page.

Some WEb containers-> tomcat (most used), glassfish, jetty, webspl

💡 Client (send request)->server (receive request)-> <if page not there or build at run time>->helper (process request)->web container (check to which servet the requst should go)-> (servelet provide HTML page)->client (send HTML page)

💡 We have a file Deployment Descriptor (web.xml) in server. in which it is mentioned that for which request we should call which servlet.
<web-app>
    <servlet>
        <servlet-name>hello</servlet-name>
        <servlet-class>com.mishra.kalyan.HelloServlet</servlet-class>
    </servlet>

    <servlet-mapping>
        <servlet-name>hello</servlet-name>
        <url-pattern>/hello</url-pattern>
    </servlet-mapping>
</web-app>

but in modern programming we can avoide this xml code with mapping using annotations.
@WebServlet("/hello")

------In short-
1. We have client machine->requst goto server 
2. server request goes to web container 
3. web container uses a file called web.xml to detect which servelet to call
4. that serverlet process the information
5. send response to client meahine


-------Download eclipse- (Download tomcat) Configure tomcat in eclipse  1:00:45:00
Change workspace in eclipse-> Go to File > Switch Workspace > Other (select location and tick copy prefrences and settings)



EE edition-> https://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/2024-09/R/eclipse-jee-2024-09-R-win32-x86_64.zip
Tomcat (64-bit Windows zip)-> https://tomcat.apache.org/download-90.cgi

if(below tabe now showing server ) in window->show view->servers->
click on link-> "No servers are available Click this link to create a new server" ->Apache->Tomcat v9.0 server ->next->Browsr Apache Tomcat v9.0 wala zip. _>Finish


Check if success running->SErvers-> Right click on Tomcat v9.0 click start.  🎉
(When it not work then maybe PORT no. used already 8080 so change the port number.)

goto localhost:8080 Wooah🎉 


Creating->Project (1:00:56:00)

File->new->project->web->Dynamic web project->next
Project name-> DemoApp  ->next->next
Tick generate web.xml deployement descritor ->finish.


improtant file.
Demo->src->main->webapp->web-inf->web.xml (niche hoga click source) This is where we configure application.

demoapp->right click->create html file->index.html
<!DOCTYPE html>
<html>
<body>
	<form action="add">
		Enter 1st number: <input type="text" name="num1"></input><br>
		Enter 2nd number: <input type="text" name="num2"></input><br>
		<input type="Submit">
	</form>
</body>
</html>

right click in this file->run on server->tomcat 9.0


Here when we submit then it will goto page called /add so we need ServLet to handle this. (Javascript jaise hai route)
we can use js within file but we need server side code to ServLet.

DemoApp->new->class->  package name com.kalyan  name AddServeLetSum   ->finish
1. we have to use server method in server component.
2. use request and response object. from HttpServlet.
3. this req obj will have the data and response obj will send the data.
4. use getParameter to get the data.   this method give string if we want in int then use Integer.parseInt 
5. use add method to add the data.

AddServlet.java 🌏
    package com.kalyan;

    import javax.servlet.http.HttpServlet;
    import javax.servlet.http.HttpServletRequest;
    import javax.servlet.http.HttpServletResponse;
    import java.io.IOException;
    import java.io.PrintWriter;

    public class AddServlet extends HttpServlet { 

        public void service(HttpServletRequest req, HttpServletResponse res) throws IOException {
            int i = Integer.parseInt(req.getParameter("num1"));
            int j = Integer.parseInt(req.getParameter("num2"));
            int k = i + j;

            PrintWriter out = res.getWriter();
            out.println("Result is: " + k);
        }
    }


in web.xml  (remove default code) 

->now we'll configure our page. (when user goto add then show page.) For every servelet we'll cerate searvlet and searvlet Mapping.

    <?xml version="1.0" encoding="UTF-8"?>
    <web-app xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://xmlns.jcp.org/xml/ns/javaee" xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_4_0.xsd" id="WebApp_ID" version="4.0">
    
    <servlet>
        <servlet-name>abc</servlet-name>
        <servlet-class>com.kalyan.AddServlet</servlet-class>
    </servlet>
    
    <servlet-mapping>
        <servlet-name>abc</servlet-name>
        <url-pattern>/add</url-pattern>
    </servlet-mapping>
    </web-app>


-----so restart the server and to show output on screen using res.getWriter() bcoz servlet is sending response;

project->clean  (solves problem sometime while starting the server error).

-----GET & POST method-----
while submitting we can see ths url is there http://localhost:8080/DemoApp/add?num1=3&num2=4
so by default it is get.
in case method="post" in form  url is http://localhost:8080/DemoApp/add

so-> when getting data from server use get.  
     when submitting data to server use post.



so we mentioned get and post in form but user can change and still see using inspect element change get to post.
so we have HttpServlet and inside that it give us doPost and doGet method. 

change method name to 
<form action="add" method="POST"> 
public void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {


public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {



-------💡🎉🤡-1:01:22:39 RequestDispatcher calling a Servelet from another Servelet
Eg:- if we have complex operation 
basic eg:- we have multiply and divide so we can make multiply in another servlet and call it. same for divide.
DemoApp->new->class->SqServlet  ->finish  extending class HttpServlet

create instance of dispatcher and call it from the parent servlet. 
    RequestDispatcher rd = req.getRequestDispatcher("SqServlet");
    rq.forward(req, res);


SqServlet.java
    public class SqServlet extends HttpServlet  { 
	    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		    PrintWriter out = res.getWriter();
		    out.println("Hello to sq");
	    }
    }   

AddServlet.java (Parent from which we will dispatch/call SqServlet)
    public class AddServlet extends HttpServlet {
        private static final long serialVersionUID = 1L;
    
        public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
            int i = Integer.parseInt(req.getParameter("num1"));
            int j = Integer.parseInt(req.getParameter("num2"));
            int k = i + j;

            RequestDispatcher rd = req.getRequestDispatcher("sq");
            rd.forward(req, res);
        }
    }

index.html
    <!DOCTYPE html>
    <html>
    <body>
        <form action="add" > 
            Enter 1st number: <input type="text" name="num1"></input><br>
            Enter 2nd number: <input type="text" name="num2"></input><br>
            <input type="Submit">
        </form>
    </body>
    </html>

and in the web.xml
    <servlet>
        <servlet-name>RequestDispatcher</servlet-name>
        <servlet-class>com.kalyan.SqServlet</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>RequestDispatcher</servlet-name>
        <url-pattern>/sq</url-pattern>
    </servlet-mapping>

-----------1:01:28:38-------Sending value from one servelet(AddServlet) to other servelet (SqServlet)
we use session management to do this. (but talk later)
easy way:- attach data in req object.

AddServlet.java
    req.setAttribute("dataFromOther", 1231);

    in other servlet (AddServlet.java)
    int i = (int)req.getAttribute("dataFromOther");


 




---------------------------❌HttpServerRequest and HttpServerResponse❌---1:01:31:11-------------------
HttpServerRequest and HttpServerResponse both are interfaces but implementation and object is given by Tomcat thats why we need Tomcat.
🤡
We use RequestDispatcher to send data from one servlet to another dispatcher
so for sending within same servlet we can use request object.
for in case redirect we're using 2 diff obj so we can't use.  so we'll have to use session management.

 
------------1:01:41:15 sendRedirect URL Rewriting.
like for tulisko.com we are using paypal. so client requesting paypal.com should know that something is happening.

public class AddServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
	      int i = Integer.parseInt(req.getParameter("num1"));
	      int j = Integer.parseInt(req.getParameter("num2"));
	      int k = i + j;
	      
	      req.setAttribute("k", k);

	      RequestDispatcher rd = req.getRequestDispatcher("sq");
	      rd.forward(req, res);
	}
}
SqServlet.java
public class SqServlet extends HttpServlet  {
 
	private static final long serialVersionUID = 1L;

	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		int k = (int) req.getAttribute("k");
		k=k*k;
		
		PrintWriter out = res.getWriter();
		out.println("Result is:"+k);
	}
}

web.xml
    <servlet>
        <servlet-name>RequestDispatcher</servlet-name>
        <servlet-class>com.kalyan.SqServlet</servlet-class>
    </servlet>
    <servlet-mapping>
        <servlet-name>RequestDispatcher</servlet-name>
        <url-pattern>/sq</url-pattern>
    </servlet-mapping>


lets do same thing using sendRedirect.
AddServlet.java
    res.sendRedirect("sq");

SqServlet.java
    res.getWriter().println("Hello");

This is how we can redirect to another servlet, but wait 🛑 we want to get data hwo to do that.
AddServlet.java
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
	      int i = Integer.parseInt(req.getParameter("num1"));
	      int j = Integer.parseInt(req.getParameter("num2"));
	      int k = i + j;
	      
	      res.sendRedirect("sq?k="+k);//this is URL Rewriting 🤡  //this comes under session management
	}

SqServlet.java
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		int k = Integer.parseInt(req.getParameter("k"));
		k=k*k;
		
		PrintWriter out = res.getWriter();
		out.println("Result is:"+k); 
	}


So url reqWiring (comes under session management) is one way to transfer data from one to other servlet.
other way is Cookie

----------------------1:01:46:00---------------HttpSession Cookie 2nd way to send data to other searvlet-------
Session is given by Tomcat. 

So we can use like mainting data throught the session, when case we have to send through multiple servlet.

AddServlet.java
    public class AddServlet extends HttpServlet {    
        public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
            int i = Integer.parseInt(req.getParameter("num1"));
            int j = Integer.parseInt(req.getParameter("num2"));
            int k = i + j;
            
            HttpSession session = req.getSession();
            session.setAttribute("k",k);
            res.sendRedirect("sq");
        }
    }

SqServlet.java
public class SqServlet extends HttpServlet  {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		HttpSession session = req.getSession();
		int k = (int)session.getAttribute("k");		
		k=k*k;
		
		PrintWriter out = res.getWriter();
		out.println("Result is:"+k); 
	}
}


session.remoteAttribute("k"); //we can remove the session data.

💡we use session to maintain the Login data.


----------------Cookie-----1:01:54:30
Gofor first time- got a token and after some time we will show token and we'll get validated.

Server will send response as cookie it to client.
and client again send request to sqservlet so when client send request to sqservlet then it will send Cookie as well.

AddServlet.java
    public class AddServlet extends HttpServlet {
        public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
            int i = Integer.parseInt(req.getParameter("num1"));
            int j = Integer.parseInt(req.getParameter("num2"));
            int k = i + j;
            
            Cookie cookie = new Cookie("k", k+"");
            res.addCookie(cookie);
            
            res.sendRedirect("sq");
        }
    }

SqServlet
    public class SqServlet extends HttpServlet  { 
        public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
            int k=0;
            Cookie cookies[] = req.getCookies(); // cookies so its array
            for(Cookie c:cookies) {
                if(c.getName().equals("k"))
                    k=Integer.parseInt(c.getValue());
            }
            k=k*k;
            
            PrintWriter out = res.getWriter();
            out.println("Result is:"+k); 
        }
    }
 



 ---------------------------ServletConfig & ServletContext--------1:02:00:00
 ServletConfig & ServletContext  we use to get initial values for a servlet or a application.
 eg:- if we want to setup any filepath or any initial parameter for servlet then how do we do that?

 so we have initial vlaues for name and phone-
 <context-param>
    <param-name>name</param-name>
    <param-value>Kalyan</param-value>
 </context-param>

  <context-param>
    <param-name>Phone</param-name>
    <param-value>Samsung</param-value>
 </context-param>

 lets use this in servlet. -> so we've to use object of ServletContext and ServletConfig
 
AddServlet
public class AddServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
	     PrintWriter out = res.getWriter();
	     out.print("Hi ");
	     
	     ServletContext ctx = getServletContext();  //get name from the context
	     String str = ctx.getInitParameter("name");
	     out.print(str);
	}
}


👩🏻ServletContext is an obj which is shared by all the objects.
so what if we want to have different configuration for different servlets?;

suppose for abc i want to print name- 'Kalyan'
    and for def i want to print name- 'gungun'
so we use ServletConfig for this.



Note💡-> so if we have 5 servelet we will have 5 ServletConfig objects but only one ServletContext object.

ServletConfig-> usi servlet wale me <init-param> kr do

web.xml
 <servlet>
        <servlet-name>ABC</servlet-name>
        <servlet-class>com.kalyan.AddServlet</servlet-class>
        
        <init-param>
        	<param-name>name</param-name>
        	<param-value>DesiBoy</param-value>
        </init-param>
        
    </servlet>

AddServlet
public class AddServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
	     PrintWriter out = res.getWriter();
	     out.print("Hi ");
	     
	     ServletConfig cg = getServletConfig();
	     String str = cg.getInitParameter("name");
	     out.print(str);
	}
}

-so different value for different context go for servletConfig.
-same value for all servlet go for ServletContext.


------------------------Servlet Annotations and configuration---1:02:07:50---------------
so we do configuration in our deployement descritor (which is web.xml) that on which request which servlet to call.

we can also do this using Annotations without writing XML 🌲🎉wooha
eg:- on top of the file we can mention

eg:-
SqServlet.java

@WebServlet("/my")
public class myServlet extends HttpServlet  { 
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
        ...
        ...
    }
}

so 2 ways 1. XML, 2.Annotations to configure the servlet endpoint.