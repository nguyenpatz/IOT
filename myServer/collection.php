<?php

include 'header.php';

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <script
src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js">
</script>
</head>
<body>
    <ul>
    <?php 
    $countON = 0;
    $countOFF = 0;
    $sql = "SELECT * FROM cambien2";
    $stmt = $conn->prepare($sql);
    $stmt->execute();
    $result = $stmt->fetchAll(PDO::FETCH_ASSOC);

    foreach ($result as $value) {
        # code...
      if($value['trangthai'] == "ON") {
        $countON++;
      } else {
        $countOFF++;
      }
    ?>
    <li>
      <span><?php echo $value['thoigian'];?></span>
      <span><?php echo $value['trangthai'];?></span>
    </li>
    <?php }?>
    <?php 
        $sql = "INSERT INTO count (countON, countOFF) VALUES ($countON, $countOFF)";
        $stmt = $conn->prepare($sql);
        $stmt->execute();

        $sql = "SELECT * FROM count ORDER BY id DESC LIMIT 1";
        $stmt = $conn->prepare($sql);
        $stmt->execute();

        $ketqua = $stmt->fetchAll(PDO::FETCH_ASSOC);

        foreach ($ketqua as  $value2) {
          // code...
          // echo "Gía trị bật tắt mới nhất: ".$value2['id'];
          // echo "Số lần bật: ".$value2['countON'];
          // echo "Số lần tắt: ".$value2['countOFF'];
        }
        
    ?>
    </ul>

    <div>
    <canvas id="myChart" style="width:100%;max-width:700px"></canvas>
  </div>
</body>
<script>
var xValues = ["Số lần bật", "Số lần tắt"];
var yValues = [<?php echo $value2['countON'];?>,<?php echo $value2['countOFF'];?>];//, 44, 24, 15];
var barColors = ["red", "green"];//,"orange","brown"];

new Chart("myChart", {
  type: "bar",
  data: {
    labels: xValues,
    datasets: [{
      backgroundColor: barColors,
      data: yValues
    }]
  },
  options: {
    legend: {display: false},
    title: {
      display: true,
      text: "Số lần bật tắt"
    }
  }
});
</script>
</html>