------------JSP-----------1:02:11:20 
Why Jsp?  Java Server Pages.

we can pass html tag in println but writing long pages code is very hectic
we can also do servlet things using simply JSP  (like we cerated myServlet.java and did calculation which we can also do heere using JSP)
Addserver.Java
-
PrintWriter out = res.getWriter();
out.println("<html><body bgcolor='yellow'>" + k);
out.println("Output: "+k);
out.println("</body></html>");

so developer will write java code and deisgners will do design java programmer will not write designer.


so in JSP we write Java code in HTML.

project->right click->Jsp File->  add.jsp

in body of add.jsp
<body bgcolor='cyan'>
    <% //all code within this will consider as java code.
        int i = Integer.parseInt(req.getParameter("num1"));  
        int j = Integer.parseInt(req.getParameter("num2"));
        int k = i + j;
        out.println("Result is: " + k);
    %>
</body>

index.html
<!DOCTYPE html>
<html>
<body>
	<form action="add.jsp" > 
		Enter 1st number: <input type="text" name="num1"></input><br>
		Enter 2nd number: <input type="text" name="num2"></input><br>
		<input type="Submit">
	</form>
</body>
</html>

1. why we use servlet if we have JSP, and can we use servlet and jsp both.

------------1:02:19:50  How JSP Translated into Servlets----------
On servlet-> 
.we have to define servlet then 
.service method then 
.create object or printWriter then print hello world.

to make sum we've to 
.fetch data from 2 obj and 
.define those two objects req and res.
.then calculate.


IN case JSP we get all of these obj by default so JSP is much simpler.

SERVLET runs on TOMCAT (TOMCAT also called servlet container)
when we wrtite JSP code then that code get converted into servlet code.

only advantage of JSP is->easy to write JSP files.

SERVLET vs JSP---

SERVLET->
1. Create java class file.
2. extend that with httpSErvlet
3. create method of service doGet/doPost
4. Pass two parameter req, res
5. print using printWriter
6. import packages

import javax.servlet.http.*;  //import package eg.
public class demoJSP extends HttpServlet {
    int value =1; //declaration section

    //below is service method
    public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
        PrintWriter out = res.getWriter();
        out.println("value is: "+ value);
    }
}

JSP->  class name become jsp file name 
1. create jsp file
2. create obj of jsp
3. write html code
4. write java code


4 Types of tag in JSP- (directive, scriptlet, declaration, expression)
demoJSP.java
we dont have to create and req, res obj just use it as everything given by Tomcat servlet (and these obj called IMplicit objects).

<%@ page import="java.io.*"%>  directive tag |  this is import tag we can write java package import in it.
<%  %>  scriptlet tag | this tag called scriptlet tag we can write java code in it.
        this tag go into service method.
<%! %>  declaration tag | this is declaration section. 

<%= k %> expression tag | this is out.println method if we want to print something.


-----------------1:02:32:00----JSP to Servlet Conversion NetBeans----------
declaration
directive
scriptlet
expression


<%@page import="java.io.*"%>  //directve tag
<%@page contentType="text/html; charset=UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>JSP Page</title>
    </head>
    <body>
        <%!  // this is declaration tag
            int variableDeclaration = 22;
        %>
        <h1>Hello World!</h1>
        <%  //scriptlet  it will be part of service method
            int i=9;
            out.println(i);
        %>

        My fav number is: <%= variableExpression %>  //this is expression
    </body>
</html>


-----------------------1:02:47:52---JSP Directive page Incude Taglib---------
JSP Directive:-  3 Types
@page   - importing package
@include - importing file
@taglib - html has limited tag so if we want to use other tag like spring boot has tag which we want to use
          so we use @taglib


@page
    <% page attribute="value"  %>

here are list of attributes:
language="scripting language"  //scrpting langage by feault language="java"
extends="className"  //exetending class
import="importList"  //import packages
session="true|false" //use session in jsp
autoFlush="true|false" //bufferGet full while sending data
contentType="ctinfo" //it can me image, htmlpage, text, etc
errorPage="error_url" //exception handling
isErrorPage="true|false"
info="information" //information about page
isElIgnore="true|false" 
isThreadSafe="true|false" //make json page thread safe


like header and footer we will have this in everypage- (ejs jaise h)

<%@ include file="filename"%>
<%@ include file="header.jsp"%>

@Taglib
    <%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

    <fx:h1Kalyan> 
eg: if we want to use own tag in jsp then we use @taglib



-----------1:02:57:00---------------IMplicit object in JSP----------
Builtin Object (Can be used in scriptlet and expression)

request (HttpServletRequest)
response (HttpServletResponse)
pageContext (PageContext)
out (JspWriter) ~ PrintWriter object
session (HttpSession)
application (ServletContext)    
config (ServletConfig)

We dont have to intantiate these object directly we can use.
eg:- request.getParameter(arg0)  //no need to intiantiate the request obj

pageContext:- it refer to a page.
using this we can set and use attribute within a page.
Its Scope is within Same page.
pageContext.serAttribute("name", "kalyan");


we can also scope //scoping to session
pageContext.setAttributes("name", "kalyan", PageContext.SESSION_SCOPE);

other we have used previously.

--------1:03:03:00-----Exception Handling in JSP-----------------------------------------------
<%
try{
        int k=9/0;
}catch(Exception e){
    out.println("Exception occured");
}
%>

This wont look good in case of web development
AS in web world we create a dadicated page which can have yes other colors. lets do that.


 under the WebContent or src/main/webapp folder, create a new error.jsp file.
folder → New → JSP File.


error.jsp

<% exception %> this is an object which only works in error page.
so we've to include isErrorPage="true"

<%@ page isErrorPage="true" %>
<!DOCTYPE html>
<html>
<head>
    <title>Error Page</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f8d7da;
            color: #721c24;
            padding: 20px;
        }
        .container {
            text-align: center;
            padding: 50px;
            background-color: white;
            border: 1px solid #f5c6cb;
            margin: 0 auto;
            max-width: 600px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Something went wrong!</h1>
        <p>An error occurred while processing your request.</p>
        <p>Error Details: <strong><%= exception %></strong></p>
        <p>Please try again later or contact support.</p>
    </div>
</body>
</html>


 	🤡web.xml 🤡

    <servlet>
        <servlet-name>ABC</servlet-name>
        <servlet-class>com.kalyan.AddServlet</servlet-class>         
    </servlet>
    
    
    <servlet-mapping>
        <servlet-name>ABC</servlet-name>
        <url-pattern>/add</url-pattern>
    </servlet-mapping>
    
 	<error-page>
    	<error-code>500</error-code>
    	<location>/error.jsp</location>
	</error-page>

	<error-page>
    	<exception-type>java.lang.ArithmeticException</exception-type>
    	<location>/error.jsp</location>
	</error-page>


index.html- 🔥
<!DOCTYPE html>
<html>
<body>
	<form action="add" >  
		<input type="Submit">
	</form>
</body>
</html>



Addservlet.java 🔥
package com.kalyan;
 
import javax.servlet.ServletException; 
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse; 

import java.io.IOException;
 
public class AddServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
 
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
		int k= 9/0;
	}
}



-----------------JDBC in JSP  1:03:10:28


File->new->project->web->Dynamic web project->next
Project name-> DemoJSP  ->next->next
Tick generate web.xml deployement descritor ->finish.
 
 project->new->jsp page->profile.jsp

 now weite JDBC 7 steps-
 /*
 *  1. Import package   ->java.sql.*
    2. Load and Register the driver -> forMysql com.mysql.jdbc.Driver  Download from https://mvnrepository.com/artifact/mysql/mysql-connector-java
    3. Establish the Connection
    4. Cerate the statement
    5. Execute the query 
    6. Process Result 
    7. Close
 *


    Driver for postGre-> org.postgresql.Driver
               URL: jdbc:postgresql://localhost:5432/kalyan

        for mysql   -> com.mysql.jdbc.Driver
 
