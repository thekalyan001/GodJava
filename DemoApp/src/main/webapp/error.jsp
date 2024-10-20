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
