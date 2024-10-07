package com.kalyan;

 import javax.servlet.ServletConfig;
import javax.servlet.ServletContext;
import javax.servlet.ServletException; 
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse; 

import java.io.IOException;
import java.io.PrintWriter; 

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
