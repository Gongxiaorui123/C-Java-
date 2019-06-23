<%@ page import="java.sql.*" pageEncoding="utf-8" errorPage="error.jsp"%>
<html>
<head>
<title>修改完成</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<%
		request.setCharacterEncoding("utf-8");
	 String name = request.getParameter("name");
	 String gender = request.getParameter("gender");
	 String birthday = request.getParameter("birthday");
	 String address = request.getParameter("address");
		String sno = request.getParameter("sno");
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/StudentManagement?useUnicode=true&characterEncoding=utf-8", "root",
				"123456");
		Statement stmt = con.createStatement();		
		String sql = "update student set name='" + name + "',gender='" + gender +"',address='" + address + "',birthday='" + birthday+ "' where sno=" + sno;		
		int i = stmt.executeUpdate(sql);
		if (i == 1) {
			out.println("<h2>修改成功！</h2><br/>");
			out.println("<a href='index.jsp'>返回首页</a>");
		} else {
			out.println("<h2>修改失败！</h2><br/>");
			out.println("<a href='edit.jsp?sno='" + sno + ">重新添加</a>");
		}
		stmt.close();
		con.close();
	%>
</body>
</html>
