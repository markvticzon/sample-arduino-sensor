<?php

    // Prepare variables for database connection

  //  $dbusername = "arduino";  // enter database username, I used "arduino" in step 2.2
//    $dbpassword = "arduinotest";  // enter database password, I used "arduinotest" in step 2.2
    $server = "localhost"; // IMPORTANT: if you are using XAMPP enter "localhost", but if you have an online website enter its address, ie."www.yourwebsite.com"

    // Connect to your database

    $dbconnect = mysql_pconnect($server);
    $dbselect = mysql_select_db("fingerprintsample",$dbconnect);

    // Prepare the SQL statement

    $sql = "INSERT INTO fingerprintsample.sensor (value) VALUES ('".$_GET["value"]."')";

    // Execute SQL statement

    mysql_query($sql);

?>
