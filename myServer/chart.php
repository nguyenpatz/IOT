<?php 

include 'header.php';


$cambien = "SELECT * FROM cambien2";

$stmt = $conn->prepare($cambien);

$stmt->execute();

$result = $stmt->fetchAll(PDO::FETCH_ASSOC);


// 2 biến đếm số lần bật tắt đèn
$countON = 0;

$countOFF = 0;

foreach ($result as $value) {
	// code...
	if($value['trangthai'] == 'ON') {
		$countON += 1;
	} else {
		$countOFF += 1;
	}
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
	<!-- <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/3.6.2/chart.min.js"> -->
	<script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.5.0/Chart.min.js"></script>

</head>
<body>

	<div>

		<canvas id="pie-chart" width="800" height="450"></canvas>


	</div>
	
</body>

<script>

	// var ctx = document.getElementById('myChart');

	// const config = {

	//   type: 'pie',

	//   data: data,
	// };

	// const data = {
	//   labels: [

	//     'ON',

	//     'OFF',
	//   ],
	//   datasets: [{

	//     label: 'Biểu đồ hiện thị phần % số lần bật tắt',

	//     data: [300, 50],

	//     backgroundColor: [

	//       'rgb(255, 99, 132)',

	//       'rgb(54, 162, 235)',

	//     ],
	//     hoverOffset: 4
	//   }]
	// };

	// new Chart(ctx, function(config,data) {

	// });


	// new Chart(ctx, {
	// 	type: 'pie',

	// 	data: {

	// 		labels: ['ON', 'OFF'],

	// 		datasets: [{

	// 			label: "Cảm biến", 

	// 			data: [100,50],

	// 			backgroundColor: [

	// 				'rgb(255, 99, 132)',

	//       			'rgb(54, 162, 235)'
	// 			],

	// 			hoverOffset: 4
	// 		}]

	// 	}
	// });

	new Chart(document.getElementById("pie-chart"), {
    type: 'pie',
    data: {
      labels: ["ON", "OFF"],
      datasets: [{
        label: "Cảm biến",
        backgroundColor: ["rgb(255, 99, 132)", "rgb(54, 162, 235)"],
        data: [<?php echo $countON;?>,<?php echo $countOFF;?>]
      }]
    },
    options: {
      title: {
        display: true,
        text: 'Số lần bật tắt đèn'
      }
    }
});


	

</script>

</html>