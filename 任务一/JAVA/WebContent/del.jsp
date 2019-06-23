<%@ page contentType="text/html; charset=gbk" language="java" import="java.sql.*" pageEncoding="utf-8"%>
<html>
<head>
<title>删除学生信息</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<%
	request.setCharacterEncoding("gbk");
	Class.forName("com.mysql.jdbc.Driver");
	Connection con=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/StudentManagement?useUnicode=true&characterEncoding=utf-8", "root",
			"123456");
	Statement stmt=con.createStatement();
	String sno=request.getParameter("sno");
	int i=stmt.executeUpdate("delete from student where sno="+sno);
	if(i==1)
	{
		out.println("<h2>删除成功！</h2><br/>");
	}
		else
	{
		out.println("<h2>删除失败！</h2><br/>");
	}
	out.println("<a href='index.jsp'>返回首页</a>");
	con.close();
	stmt.close();
	%>
</body>
</html>
