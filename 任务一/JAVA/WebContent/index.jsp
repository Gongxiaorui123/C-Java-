<%@ page language="java" import="java.sql.*" pageEncoding="utf-8"%>
<%@ page errorPage="error.jsp"%>
<html>
<head>
<title>学生信息管理系统</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<h1>学生信息管理系统</h1>
	<a href="add.jsp">添加学生信息</a>
	<br />
	<br />
	<table style="width: 50%;">
		<tr>
			<th>姓名</th>
			<th>性别</th>
			<th>出生日期</th>
			<th>地址</th>
			<th>管理</th>
		</tr>
		<%
			try {
				Class.forName("com.mysql.jdbc.Driver");
				Connection con = DriverManager.getConnection(
						"jdbc:mysql://127.0.0.1:3306/StudentManagement?useUnicode=true&characterEncoding=utf-8", "root",
						"asdfgh");
				//使用Statement对象
				Statement stmt = con.createStatement();
				String s = "select * from student";
				ResultSet rs = stmt.executeQuery(s);

				/*
				PreparedStatement stmt = con.prepareStatement("select * from bookinfo");
				ResultSet rs = stmt.executeQuery();
				*/
				while (rs.next()) {
					int sno= rs.getInt(1);
					out.println("<tr><td>" + rs.getString(2) + "</td><td>" + rs.getString(3) + "</td><td>"
							+ rs.getString(4) + "</td><td>" + rs.getString(5) + "</td><td><a href='edit.jsp?sno=" + sno
							+ "'>修改</a>&nbsp;<a href='del.jsp?sno=" + sno + "'>删除</a></td></tr>");
				}
				rs.close();
				stmt.close();
				con.close();
			} catch (Exception e) {
				out.println("Exception:" + e.getMessage());
			}
		%>
		
	</table>
	<br />
	<hr />
	<div style="text-align: center; width: 100%; font-size: 12px; color: #333;">
		&copy;版权所有：石家庄铁道大学信息科学与技术学院&nbsp;&nbsp;<a href="Lab03.png" target="_blank">网站地图</a>
	</div>
</body>
</html>
