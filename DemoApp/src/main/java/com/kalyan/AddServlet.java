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
