const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>

<html>

<head>
  <meta charset="UTF-8">
  <link rel="stylesheet" href="E:\HTML-CSS\assets\fonts/fontawesome-free-6.2.0-web/css/all.css">
  <script src="https://kit.fontawesome.com/251dd34c64.js" crossorigin="anonymous"></script>
  <link rel="icon" href="https://luv.vn/wp-content/uploads/2021/09/tranh-ve-phong-canh-ha-noi-17-1.jpg"
    type="image/x-icon" />


  <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js"></script>
  
  <title>GIÁM SÁT NÔNG NGHIỆP</title>
  <style>
    html {
      width: 100%;
      height: 100%;
      background-image: url(https://thuthuatnhanh.com/wp-content/uploads/2021/12/Background-cay-xanh-phong-canh-dep.jpg);
      background-repeat: no-repeat;
      background-size: contain;
      background-position: center;


    }
    #home {
      display: block;
      width: 750px;
      height: 450px;
      margin: 40px auto auto auto;
      border: 5px solid rgba(138, 27, 27, 0.7);
      border-radius: 3px;
      box-shadow: 0 3px 5px #155d06;

      align-items: center;
      position: relative;


    }




    .main {
      color: aqua;
      text-align: center;
      margin: auto 31px;


    }

    h1 {
      color:rgb(88, 5, 8);

    }

    .content {
      margin: 30px auto;
      color: #fff;
    }

    .temp,
    .fah,
    .humi,
    .soid,
    .light {
      display: flex;
      height: 50px;
      width: 600px;
      margin: auto;
      border: 3px solid #1bc4c1;
      border-radius: 4px;
      box-shadow: 0 3px 5px #053d62;
      ;
    }

    .temp i,
    .fah i,
    .humi i,
    .soid i,
    .light i {
      margin: auto 5px;

    }



    .temp i,
    .temp h2 {
      color: red;
      margin: auto 5px;
    }

    .fah i,
    .fah h2 {
      color: blue;
      margin: auto 5px;
    }

    .humi i,
    .humi h2 {
      color: green;
      margin: auto 5px;
    }

    .soid i,
    .soid h2 {
      color: brown;
      margin: auto 5px;
    }

    .light i,
    .light h2 {
      color: orange;
      margin: auto 5px;
    }



    .temp+.fah {
      margin-top: 10px;
    }

    .fah+.humi {
      margin-top: 10px;
    }

    .humi+.soid {
      margin-top: 10px;
    }

    .soid+.light {
      margin-top: 10px;
    }


    .light+.nutnhan {
      margin-top: 70px;
    }

    .nutnhan+.nutnhan{
      margin-top: 15px;
    }




    .nutnhan {
      display: flex;
      justify-content: space-around;
    }

    .btn {
      min-width: 120px;
      max-width: 200px;
      height: 50px;
      box-sizing: border-box;
      outline: none;
      color: #fff;
      padding: 4px 4px;
      border-radius: 50px;
      cursor: pointer;

      margin: auto;
      text-align: center;
      font-size: 25px;
      font-weight: 900;
      z-index: 2;
      box-shadow: 3px 3px 3px 3px #212129;

    }


    #led,
    #led1,
    #fan,
    #fan1,
    #pump,
    #pump1 {
      display: none;
    }

    .btn_on {
      background-image: linear-gradient(135deg, #E83507, #86d472);
      display: block;




    }

    .btn_off {

      background-image: linear-gradient(135deg, #e1e822, #1eb3c7);
      display: block;



    }

    .btn_on .btn_1,
    .btn_off .btn_1 {

      background: black;
      border-radius: 50px;
      height: 100%;
      transition: background 0.5s ease;
      width: 100%;
      display: flex;
      justify-content: center;
      align-items: center;
      margin-bottom: 16px;
    }


    .btn_on:hover .btn_1 {
      background: transparent;
      opacity: 0.9;
      color: #0e0e10;
    }

    .btn_off:hover .btn_1 {
      background: transparent;
      opacity: 0.9;
      color: #0e0e10;

    }






    a {
      text-decoration: none;
      margin-bottom: 16px;
    }



    .slidecontainer {
      /*width: 50%;*/
    }

    .slid {
      -webkit-appearance: none;
      width: 300px;
      height: 25px;
      border-radius: 5px;
      background: #111;
      outline: none;
      border-radius: 12px;
      overflow: hidden;
      box-shadow: inset 0 0 5px rgba (0, 0, 0, 1);
    }

    #toast .slid_change {
      width: 1000px;
    }

    .slid::-webkit-slider-thumb {
      -webkit-appearance: none;

      width: 19px;
      height: 19px;
      border-radius: 50%;
      background: #ec1249;
      cursor: pointer;
      border: 4px solid rgb(247, 176, 176);
      box-shadow: -560px 0 0 550px #f10a0a;
    }

    #quay,
    #do {
      font-family: Arial, Helvetica;
      color: #870808;
      font-size: 20px;
      text-align: center;
      font-weight: 700;
    }

    .slid+#quay {
      margin-top: 6px;
      margin-bottom: 7px;
    }







    #toast {

      display: none;
      border-radius: 2px;
      padding: 20px 0;
      width: 1200px;
      border-left: 9px solid #054e11;
      box-shadow: 0 7px 12px rgba(5, 7, 0, 0.4);
      transition: all linear 0.3s;
      /*background-color: #fafafa;*/
      align-items: center;
      background-color: rgba(206, 243, 212, 0.5);
      margin: 100px auto auto auto;


    }

    #toast div {

      text-align: center;
      margin: auto;
    }

    #intro {
      text-align: center;
      margin: 10px 0px 30px;
    }

    .btn_click {
      display: flex;
      width: 125px;
      height: 40px;
      border: none;
      border-radius: 2px;
      padding: 2px 8px;
      cursor: pointer;
      color: #fff;
      background-color: white;


      background-color: #ee4b2b;


    }

    .btn_click h1 {
      font-size: 25px;
      margin: auto;

    }

    .slid+#quay {
      margin-top: 18px;
      margin-bottom: 21px;
    }

    #icon {
      color: #1b6306;
      font-size: 50px;
      font-weight: 700;

      position: absolute;

      top: 20px;
      left: -200px;
      z-index: -1;
      cursor: pointer;
    }



    .control i {
      font-size: 30px;
      color: #5b2e12;
      margin-left: 10px;
    }

    .control {
      display: flex;
      text-align: center;
      align-items: center;
      max-width: 141px;
      cursor: pointer;
      height: 50px;

    }

    .control h4 {
      font-size: 20px;
      margin-left: 10px;
    }

    #icon_home {
      background-color: rgba(0, 255, 0, 0.5);
    }

    .control+.control {
      margin-top: 0px;
    }

    .control:hover {
      background-color: rgba(0, 255, 0, 0.5);

    }

    .location {
      position: absolute;
      width: 141px;
      top: 0px;
      left: 0px;

    }

    #myChart {

      padding: 15px;
      border: 5px solid #0f580f;
      border-radius: 3px;
      margin: 75px auto auto auto;
      width: 100%;
      max-width: 1200px;
      background-color: rgba(255, 255, 255, 0.5);
      z-index: -1;


    }
  </style>
</head>

<body>

  <div id="home">

    <div class="main">
      <h1>CAP NHAT TINH HINH TRONG NHA KINH</h1>

    </div>
    <div class="content">
      <div class="temp">
        <i class="fa-solid fa-temperature-half"></i>
        <h2>HIEN THI NHIET DO:
          <span id="nhietdos">0</span>°C
        </h2>

      </div>
      <div class="fah">
        <i class="fa-solid fa-droplet"></i>
        <h2>HIEN THI NHIET DO TINH THEO DO F:
          <span id="nhietdoFs">0</span>°F

        </h2>

      </div>
      <div class="humi">
        <i class="fa-solid fa-percent"></i>
        <h2>HIEN THI DO AM:
          <span id="doams">0</span>%


        </h2>
      </div>

      <div class="soid">
        <i class="fa-solid fa-land-mine-on"></i>
        <h2>HIEN THI DO AM CUA DAT:
          <span id="doamdats">0</span>%
        </h2>
      </div>



      <div class="light">
        <i class="fa-regular fa-sun"></i>
        <h2>TINH HINH ANH SANG:
          <span id="anhsangs">0</span>
        </h2>
      </div>





    <div class="nutnhan">
        <div class="led" id="led" title="1">
            <div class="btn btn_on">
                <div class="btn_1">ON LED</div>
            </div>
        </div>


        <div class="fan" id="fan" title="1">
            <div class="btn btn_on">
                <div class="btn_1">ON FAN</div>
            </div>
        </div>


        <div class="pump" id="pump" title="1">
            <div class="btn btn_on">
                <div class="btn_1">ON PUMP</div>
            </div>
        </div>
    </div>




    <div class="nutnhan">
        <div class="led" id="led1" title="0">
            <div class="btn btn_off">
                <div class="btn_1">OFF LED</div>
            </div>
        </div>


        <div class="fan" id="fan1" title="0">
            <div class="btn btn_off">
                <div class="btn_1">OFF FAN</div>
            </div>
        </div>


        <div class="pump" id="pump1" title="0">
            <div class="btn btn_off">
                <div class="btn_1">OFF PUMP</div>
            </div>
        </div>
    </div>




      <div class="nutnhan">
        <div class="servo_1">
          <div class="slidecontainer">
            <input type="range" min="0" max="180" value="0" class="slid" id="my">
            <p id="quay">QUAY : <span id="demo"></span><span id="do"> ĐỘ</span></p>
          </div>
        </div>

        <div class="servo_2">
          <div class="slidecontainer">
            <input type="range" min="0" max="180" value="0" class="slid" id="myRange">
            <p id="quay">Quay : <span id="mydemo"></span><span id="do"> độ</span></p>
          </div>
        </div>


      </div>
    </div>
  </div>






  <div class="setting">


    <div id="toast">

      <h1 id="intro">Thiet lap dieu khien tu dong</h1>
      <div class="slidecontainer">
        <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my0">
        <p id="quay">Nhiet do: <span id="demo0"></span><span id="do"> °C</span></p>
      </div>

      <div class="slidecontainer">
        <input type="range" min="0" max="120" value="0" class="slid slid_change" id="my1">
        <p id="quay">Thoi gian quat: <span id="demo1"></span><span id="do"> s</span></p>
      </div>


      <div class="slidecontainer">
        <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my2">
        <p id="quay">Do am dat: <span id="demo2"></span><span id="do"> %</span></p>
      </div>

      <div class="slidecontainer">
        <input type="range" min="0" max="120" value="0" class="slid slid_change" id="my3">
        <p id="quay">Thoi gian bom: <span id="demo3"></span><span id="do"> s</span></p>
      </div>




    </div>
  </div>


  <canvas id="myChart" style="display: none;"></canvas>


  <div class="location">
    <div id="icon_home" class="control" onclick="button_home()">
      <i class="fa-sharp fa-solid fa-house"></i>
      <h4>Home</h4>

    </div>

    <div id="icon_chart" class="control" onclick="button_chart()">
      <i class="fa-sharp fa-solid fa-chart-line"></i>
      <h4>Chart</h4>


    </div>

    <div id="icon_setting" class="control" onclick="button_setting()">
      <i class="fa-sharp fa-solid fa-gear"></i>
      <h4>Setting</h4>


    </div>

    <div id="icon_video" class="control" onclick="button_video()">
      <i class="fa-solid fa-video"></i>
      <h4>Video</h4>

    </div>
  </div>














  <script>


    var nhietdo;
    var doam;
    var doamdat;


    var thoigian = [];
    var giatri = [];

    var giatri_2 = [];

    var giatri_3 = [];

    var bieudo = document.getElementById("myChart").getContext('2d');

        getkiemtraNT();
        getkiemtraDAD();
    setInterval(function () {
      // Call a function repetatively with 2 Second interval
      getnhietdo();
      getnhietdoF();
      getdoam();
      //------------------
      getdoamdat();
      getanhsang();


    }, 1000); //2000mSeconds update rate



     function getkiemtraNT() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("my0").value = this.responseText;
                    document.getElementById("demo0").innerHTML = this.responseText;
                    console.log(this.responseText);


                }
            };
            xhttp.open("GET", "kiemtraNT", true);
            xhttp.send();
        }

        function getkiemtraDAD() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {

                    
                    document.getElementById("my2").value = this.responseText;
                    document.getElementById("demo2").innerHTML = this.responseText;
                    console.log(this.responseText);


                }
            };
            xhttp.open("GET", "kiemtraDAD", true);
            xhttp.send();
        }
   
    
    

    function getnhietdo() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("nhietdos").innerHTML = this.responseText;

          nhietdo = parseInt(this.responseText);
          if (this.responseText == "Failed") {
            
              document.getElementById("fan").style.display = "block";

            
            
               document.getElementById("fan1").style.display = "block";
            
            
           


          }

          else {
            document.getElementById("fan").style.display = "none";
            document.getElementById("fan1").style.display = "none";

          }

        }
      };
      xhttp.open("GET", "docnhietdo", true);
      xhttp.send();
    }



    function getnhietdoF() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("nhietdoFs").innerHTML = this.responseText;


        }
      };
      xhttp.open("GET", "docnhietdoF", true);
      xhttp.send();
    }



    function getdoam() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("doams").innerHTML = this.responseText;

          doam = parseInt(this.responseText);

        }
      };
      xhttp.open("GET", "docdoam", true);
      xhttp.send();
    }

    //------------------------------------------

    function getdoamdat() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("doamdats").innerHTML = this.responseText;

          doamdat = parseInt(this.responseText);

          console.log(fan);

          if (this.responseText == "Failed") {

            
                 document.getElementById("pump").style.display = "block";
            
            
            
              document.getElementById("pump1").style.display = "block";

            
            
          }

          else {
            document.getElementById("pump").style.display = "none";
            document.getElementById("pump1").style.display = "none";
          }

        }
      };
      xhttp.open("GET", "docdoamdat", true);
      xhttp.send();
    }



    function getanhsang() {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          document.getElementById("anhsangs").innerHTML = this.responseText;
           

          if (this.responseText == "Failed") {
            
               document.getElementById("led").style.display = "block";
            
            
                document.getElementById("led1").style.display = "block";
            
         


          }

          else {
            document.getElementById("led").style.display = "none";
            document.getElementById("led1").style.display = "none";

          }



        }
      };
      xhttp.open("GET", "docanhsang", true);
      xhttp.send();
    }

    setInterval(function () {
      const d = new Date();
      let hour = d.getHours();

      let phut = d.getMinutes();



      var time = hour.toString() + ":" + phut.toString();

      thoigian.push(time);

      console.log(thoigian);
      if (thoigian.length == 11) {
        thoigian.shift()
      }




    }, 10000);



    setInterval(function () {
      giatri.push(nhietdo);
      giatri_2.push(doam);
      giatri_3.push(doamdat)

      if (giatri.length == 11) {
        giatri.shift();
      }
      if (giatri_2.length == 11) {
        giatri_2.shift();
      }
      if (giatri_3.length == 11) {
        giatri_3.shift();
      }

    }, 10000)



    setInterval(function () {

      var line_chart = new Chart(bieudo, {
        type: "line",
        data: {
          labels: thoigian,
          datasets: [{
            label: 'Nhiệt độ',
            fill: false,
            lineTension: 0,
            backgroundColor: "rgba(205,0,0,1.0)",
            borderColor: "rgba(205,0,0,0.5)",
            data: giatri,
            tension: 0.3,
            borderWidth: 6
          },
          {
            label: 'Độ ẩm',
            fill: false,
            lineTension: 0,
            backgroundColor: "rgba(0,205,0,1.0)",
            borderColor: "rgba(0,205,0,0.5)",
            data: giatri_2,
            tension: 0.3,
            borderWidth: 6

          },
          {
            label: 'Độ ẩm đất',
            fill: false,
            lineTension: 0,
            backgroundColor: "rgba(0,0,205,1.0)",
            borderColor: "rgba(0,0,205,0.5)",
            data: giatri_3,
            tension: 0.3,
            borderWidth: 6
          }
          ]
        },
        options: {
          title: {
            display: true,
            text: 'Biểu Đồ Giám Sát Nông Nghiệp',
            fontSize: 25
          },
          scales: {
            yAxes: [{ ticks: { min: 0, max: 100 } }],
          },
        }
      });


    }, 10000)





    function button_chart() {
      document.getElementById('home').style.display = 'none';
      document.getElementById('myChart').style.display = 'block';
      document.getElementById('toast').style.display = 'none';

      document.getElementById('icon_chart').style.backgroundColor = 'rgba(0, 255, 0, 0.5)';
      document.getElementById('icon_home').style.backgroundColor = 'inherit';
      document.getElementById('icon_setting').style.backgroundColor = 'inherit';
      document.getElementById('icon_video').style.backgroundColor = 'inherit';


    }

    function button_home() {
      document.getElementById('home').style.display = 'block';
      document.getElementById('myChart').style.display = 'none';
      document.getElementById('toast').style.display = 'none';
      document.getElementById('icon_home').style.backgroundColor = 'rgba(0, 255, 0, 0.5)';
      document.getElementById('icon_chart').style.backgroundColor = 'inherit';
      document.getElementById('icon_setting').style.backgroundColor = 'inherit';
      document.getElementById('icon_video').style.backgroundColor = 'inherit';


    }
    function button_setting() {
      document.getElementById('home').style.display = 'none';
      document.getElementById('myChart').style.display = 'none';
      document.getElementById('toast').style.display = 'block';

      document.getElementById('icon_home').style.backgroundColor = 'inherit';
      document.getElementById('icon_chart').style.backgroundColor = 'inherit';
      document.getElementById('icon_setting').style.backgroundColor = 'rgba(0, 255, 0, 0.5)';
      document.getElementById('icon_video').style.backgroundColor = 'inherit';




    }


    function button_video() {
      document.getElementById('home').style.display = 'none';
      document.getElementById('myChart').style.display = 'none';
      document.getElementById('toast').style.display = 'none';

      document.getElementById('icon_home').style.backgroundColor = 'inherit';
      document.getElementById('icon_chart').style.backgroundColor = 'inherit';
      document.getElementById('icon_setting').style.backgroundColor = 'inherit';
      document.getElementById('icon_video').style.backgroundColor = 'rgba(0, 255, 0, 0.5)';




    }









    function sendData_LED(pos) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setLED?CLED=" + pos, true);
      xhttp.send();
    }

    function sendData_FAN(pos) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setFAN?CFAN=" + pos, true);
      xhttp.send();
    }

    function sendData_PUMP(pos) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setPUMP?CPUMP=" + pos, true);
      xhttp.send();
    }
    







        var button_led = document.getElementById("led");

        button_led.onclick = function () {
            sendData_LED(button_led.title)

        }

        var button_led1 = document.getElementById("led1");

        button_led1.onclick = function () {
            sendData_LED(button_led1.title);
        }


        var button_fan = document.getElementById("fan");

        button_fan.onclick = function () {
            sendData_FAN(button_fan.title);
        }

        var button_fan1 = document.getElementById("fan1");

        button_fan1.onclick = function () {
            sendData_FAN(button_fan1.title);
        }
        var button_pump = document.getElementById("pump");

        button_pump.onclick = function () {
            sendData_PUMP(button_pump.title);
        }

        var button_pump1 = document.getElementById("pump1");

        button_pump1.onclick = function () {
            sendData_PUMP(typeof button_pump1.title);
        }








































    function sendData_1(pos) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setPOS?servoPOS=" + pos, true);
      xhttp.send();
    }
    var s = document.getElementById("my");
    var o = document.getElementById("demo");
    o.innerHTML = s.value;

    s.oninput = function () {
      o.innerHTML = this.value;
      sendData_1(o.innerHTML);
    }

    function sendData(boss) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setBOSS?servoBOSS=" + boss, true);
      xhttp.send();
    }
    var slider = document.getElementById("myRange");
    var output = document.getElementById("mydemo");
    output.innerHTML = slider.value;

    slider.oninput = function () {
      output.innerHTML = this.value;
      sendData(output.innerHTML);
    }







    function sendData_NT(pos) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setKTNT?KTNT=" + pos, true);
      xhttp.send();
    }
    var s0 = document.getElementById("my0");
    var o0 = document.getElementById("demo0");
    o0.innerHTML = s0.value;

    s0.oninput = function () {
      o0.innerHTML = this.value;
      sendData_NT(o0.innerHTML);
    }



    ////





    function sendData_DAD(pos) {
      var xhttp = new XMLHttpRequest();
      xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
          console.log(this.responseText);
        }
      };
      xhttp.open("GET", "setKTDAD?KTDAD=" + pos, true);
      xhttp.send();
    }
    var s2 = document.getElementById("my2");
    var o2 = document.getElementById("demo2");
    o2.innerHTML = s2.value;

    s2.oninput = function () {
      o2.innerHTML = this.value;
      sendData_DAD(o2.innerHTML);
    }











    function button() {
      document.getElementById("toast").style.display = "none";


    }


    function click_icon() {
      document.getElementById("toast").style.display = "block";


    }






  </script>
</body>

</html>
)=====";
