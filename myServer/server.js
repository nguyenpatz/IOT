// source: NodeJS + MySQL Database Connection Tutorial
// https://www.youtube.com/watch?v=hGZX_SA7lYg
// hướng dẫn ở đây nhá
// mysql
var mysql = require('mysql');

//websocket
var WebSocket = require('ws');

//http
var http = require('http');

// fs
var fs = require('fs');
// time
// var my_time = require('moment');

// kết nối mysql
var con = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '',
    database: 'iot2' // hãy sửa đổi tên database nhá bro !!!
});

var ketquaResult;
// kiểm tra kết nối và insert data vào db
con.connect(function(err) {
    if (err) throw err;
    console.log("mysql Connected!");
    

    // lấy full data từ database 
    sql = "SELECT * FROM cambien2";
    con.query(sql, function(err,result, fields) {
        if (err) throw err;
        // console.log(result[1].noidung);
        
        // lấy kết quả từ lệnh select * from cambien
        ketquaResult = result;
        console.log(ketquaResult);

    });
    
  });



const port = 8000;

// run file index.html
function requestHandler(req, res) {
    fs.readFile('./index.html', function(err, content) {
        res.writeHead(200, {'Content-Type':'text/html'});
        res.end(content);
    })
}

//create http server
var server = http.createServer(requestHandler);
var ws = new WebSocket.Server({server});

//biến lưu các client kết nối với server
var clients = [];

function broadcast(socket, data) {
    for(let i = 0; i < clients.length; i++) {
        // xem client có bị trùng không???
        if(clients[i] != socket) {
            // gửi data từ client 
            clients[i].send(data);
        }
    }
}
// lưu lại giá trị của các cảm biến ở dạng string
var ESP = '';

// lưu giá trị để cắt chuỗi
var valueESPString = '';
// Giá trị cảm biến ánh sáng & giá trị cảm biến chuyển động
var sensorValue = [0, 0]; // sensorValue[0] cảm biến ánh sáng & sensorValue[1] cảm biến chuyển động

// var today = new Date();
// var date =today.getDate() + '-'+(today.getMonth()+1)+'-' + today.getFullYear() + '-' + today.getHours() + 'h:' + today.getMinutes() + 'p:' + today.getSeconds() +'s' ;

//broadcast: gửi dữ liệu từ server tới tất cả client
// ws.on('connection', function(socket, req) {
//     clients.push(socket);
//     socket.on('message', function(message) {
//         // tham số message lưu giá trị cảm biến của client esp 
//         console.log(message.toString());
//         ESP = date + " giá trị cảm biến: " + message.toString();
//         valueESPString = message.toString();
//         //cắt chuỗi 
//         valueESPString = valueESPString.split(" ");
//         sensorValue[0] = parseInt(valueESPString[0]);
//         sensorValue[1] = parseInt(valueESPString[1]);
//         if(message.toString() == 'ON') {
//             insertIntoDB(ESP);
//         }
//         broadcast(socket, message.toString());
//     });
//     socket.on('close', function() {
//         var index = clients.indexOf(socket);
//         clients.splice(index, 1);
//         console.log('disconnected');
//     });
// });

// ws.on('connection', function(socket){
//     socket.on('message', function message(data,isBinary) {
//         // console.log(data.toString());
//         // ESP = date + " giá trị cảm biến: " + data.toString();
        
//         })
        
//         ws.clients.forEach(function each(client){
//             if(client !== ws && client.readyState === WebSocket.OPEN) {
//                 client.send(data.toString(), {binary: isBinary})
//             }
//         });
//     });
// });


ws.on('connection', function(socket){ socket // là trình duyệt hoặc esp
    socket.on('message', function message(data,isBinary) {
        // console.log(data.toString());
        if(data.toString() == 'ON' || data.toString() == 'OFF') { // Khi ấn nút sẽ nhận data gửi về từ trình duyệt về server

            // ESP = data.toString();
            // var today = new Date();
            // var date =today.getDate() + '-'+(today.getMonth()+1)+'-' + today.getFullYear() + '-' + today.getHours() + 'h:' + today.getMinutes() + 'p:' + today.getSeconds() +'s' ;
            // console.log(data.toString());
            // valueESPString = data.toString();
            // console.log(valueESPString);
            // ESP = date + ": " + data.toString();
            // var value = [ESP, data.toString()];
            // // con.query("INSERT INTO cambien (noidung) VALUES (?)", ESP, ()=> {});
            // con.query("INSERT INTO cambien (noidung, trangthai) VALUES (?)", [value], ()=> {});

            var myTime = require('moment')().format('YYYY-MM-DD HH:mm:ss');
            ESP = data.toString();
            var value = [myTime, ESP]
            // console.log(value);
            // // var sql = "INSERT INTO cambien2 (thoigian, trangthai) VALUES (?, ?)"
            con.query("INSERT INTO cambien2 (thoigian, trangthai) VALUES (?)", [value], ()=> {});
        }
        // Gửi dữ liệu từ client này sang client khác
        ws.clients.forEach(function each(client){
            if(client !== ws && client.readyState === WebSocket.OPEN) {
                client.send(data.toString(), {binary: isBinary})
            }
        });
    });
});


server.listen(port);


// connect mysql

  

