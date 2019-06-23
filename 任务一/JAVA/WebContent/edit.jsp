<%@ page import="java.sql.*" pageEncoding="utf-8" errorPage="error.jsp"%>
<html>
<head>
<title>修改学生信息</title>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<%
		request.setCharacterEncoding("utf-8");
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/StudentManagement?useUnicode=true&characterEncoding=utf-8", "root",
				"123456");
		Statement stmt = con.createStatement();
		String sno = request.getParameter("sno");
		ResultSet rs = stmt.executeQuery("select * from student where sno=" + sno);
		rs.next();
	%>
	<form action="editsave.jsp" method="post">
		<h2>修改学生信息</h2>
		<table style="width:50%">
	
			<tr>
				<th>姓名：</th>
				<td><input name="name" type="text" value="<%=rs.getString(2)%>"></td>
			</tr>
			<tr>
				<th>性别：</th>
				<td><input name="gender" type="text" value="<%=rs.getString(3)%>"></td>
			</tr>
			<tr>
				<th >日期：</th>
				<td><input name="birthday" type="text" value="<%=rs.getString(4)%>"></td>
			</tr>
			<tr>
				<th >地址：</th>
				<td ><input name="address" type="text" value="<%=rs.getString(5)%>"></td>
			</tr>
			
			<tr>
				<td colspan="2"><input type="hidden" name="sno" value="<%=sno%>">
					<input type="submit" value="修改"> <input type="reset"
					value="重置"></td>
			</tr>
		</table>
	</form>
	<%
		rs.close();
		stmt.close();
		con.close();
	%>
</body>
</html>
