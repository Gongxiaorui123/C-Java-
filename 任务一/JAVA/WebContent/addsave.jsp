<%@ page contentType="text/html; charset=utf-8" import="java.sql.*" errorPage="error.jsp"%>
<html>
<head>
<title>添加学生信息</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<%
		request.setCharacterEncoding("utf-8");
		String submit = request.getParameter("submit");		
		String name = request.getParameter("name");
		String gender = request.getParameter("gender");
		String birthday = request.getParameter("birthday");
		String address = request.getParameter("address");
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/StudentManagement?useUnicode=true&characterEncoding=utf-8", "root",
				"123456");
		//使用Statement对象
		/*Statement stmt = con.createStatement();
		String sql = "insert into student(name,gender,birthday,address) values('" + name + "','" + gender + "','" +birthday+ "'," + address + ")";
		int i = stmt.executeUpdate(sql);*/
		
		
		String sql = "insert into student(name,gender,birthday,address) values(?, ?, ?,?)";
		PreparedStatement stmt = con.prepareStatement(sql);
		stmt.setString(1, name);
		stmt.setString(2, gender);
		stmt.setString(3, birthday);
		stmt.setString(4, address);
		int i = stmt.executeUpdate();
		
		
		if (i == 1) {
			out.println("<h2>添加成功！</h2><br/>");
			out.println("<a href='index.jsp'>返回首页</a>");
		} else {
			out.println("<h2>添加失败！</h2><br/>");
			out.println("<a href='add.jsp'>重新添加</a>");
		}
		stmt.close();
		con.close();
		
	%>
</body>
</html>
