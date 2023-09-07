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
            margin: 80px auto auto auto;
            border: 5px solid rgba(138, 27, 27, 0.7);
            border-radius: 3px;
            box-shadow: 0 3px 5px #155d06;

            align-items: center;
            position: relative;
            background-color: rgba(206, 243, 212, 0.5);


        }




        .main {
            color: aqua;
            text-align: center;
            margin: auto 31px;


        }

        h1 {
            color: rgb(88, 5, 8);

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


        .container+.nutnhan {
            margin-top: 40px;
        }

        .nutnhan+.nutnhan {
            margin-top: 30px;
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
            display: block;
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

            max-height: 700px;


        }

        #toast div {

            text-align: center;
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
            max-width: 135px;
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
            width: 135px;
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







        .container {
            height: 50px;
            text-align: center;
            display: flex;
            justify-content: center;

        }

        .container .toggle {
            position: relative;
            width: 120px;
            height: 50px;
            background: linear-gradient(135deg, #ff3300, #86d472);
            border-radius: 30px;
        }

        .container .toggle.active {
            background: linear-gradient(135deg, #e1e822, #1eb3c7);
        }

        .container .toggle.active .toggle-button {
            left: 72px;
        }

        .container .toggle .toggle-button {
            position: absolute;
            top: 2px;
            left: 2px;
            width: 40px;
            height: 40px;
            border: 3px solid #333;
            background: rgb(237, 230, 230);
            border-radius: 50%;
            cursor: pointer;
            z-index: 1;
        }

        .container .text {
            position: relative;
            left: 10px;
            top: 8px;
            font-size: 25px;
            font-family: Arial, Helvetica, sans-serif;
            margin-left: 10px;
        }



        :root {
            --primary-color: #ee4b2b;

            --white-color: #fff;
            --black-color: #000;
            --text-color: #333;
            --border-color: #dbdbdb;
            --star-gold-color: #ffce3e;
            --navbar-height: 34px;
            --header-height: 120px;
            --header-with-search-height: calc(var(--header-height) - var(--navbar-height));
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
            }

            to {
                opacity: 1;
            }

        }

        @keyframes growth {
            from {
                transform: scale(var(--growth-from));
            }

            to {
                transform: scale(var(--growth-to));
            }
        }


        #change_img {
            display: none;
        }



        .modal {
            position: fixed;
            top: 0;
            right: 0;
            left: 0;
            bottom: 0;
            display: flex;
            animation: fadeIn linear 0.1s;

        }

        .modal__overlay {
            position: absolute;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.4);

        }

        .modal__body {
            --growth-from: 0.5;
            --growth-to: 1;
            margin: auto;
            position: relative;
            z-index: 1;
            animation: growth linear 0.3s;

        }



        .auth-form {
            background-color: var(--white-color);
            width: 500px;
            border-radius: 5px;
            overflow: hidden;
        }


        .auth-form__container {
            padding: 0 32px;
        }

        .auth-form__header {
            display: flex;
            align-items: center;
            justify-content: space-between;
            padding: 0 12px;
            margin-top: 10px;
        }

        .auth-form__heading {
            font-size: 20px;
            font-weight: 400;
            color: var(--text-color);
        }

        .auth-form__form {
            width: 100%;
        }

        .auth-form__group {
            width: 100%;

        }

        .auth-form__input {
            width: 94%;
            height: 40px;
            margin-top: 16px;
            padding: 0 12px;
            font-size: 1rem;
            border: 2px solid var(--border-color);
            border-radius: 2px;
            outline: none;
        }

        .auth-form__input:focus {
            border-color: #777;
        }


        .auth-form__controls {
            margin-top: 40px;
            display: flex;
            justify-content: flex-end;
        }






        .btnXN {
            min-width: 124px;
            height: 34px;
            text-decoration: none;
            border: none;
            border-radius: 2px;
            font-size: 1rem;
            padding: 0 12px;
            outline: none;
            cursor: pointer;
            color: var(--text-color);
            background-color: white;
            font-weight: 400;
            display: inline-flex;
            justify-content: center;
            align-items: center;
            line-height: 1.6rem;
            margin-bottom: 10px;
            margin-top: 15px;

        }



        .btnXN.btn--primary {
            color: var(--white-color);
            background-color: var(--primary-color);
        }

        .btn--primary:hover {
            opacity: 0.8;
            color: #000;
        }



        #select i {
            position: fixed;
            top: 740px;
            left: 14px;
            cursor: pointer;
        }

        #select i:hover {
            opacity: 0.8;
            background-color: #78ea70;
            color: #042c06 !important;


        }

        #select p {
            position: absolute;
            top: 730px;
            left: 60px;
            font-size: 20px;
        }
  </style>
</head>

<body>

   <div id="home">

        <div class="main">
            <h1>CẬP NHẬT TÌNH HÌNH TRONG NHÀ KÍNH</h1>

        </div>
        <div class="content">
            <div class="temp">
                <i class="fa-solid fa-temperature-half"></i>
                <h2>HIỆN THỊ NHIỆT ĐỘ:
                    <span id="nhietdos">0</span>°C
                </h2>

            </div>
            <div class="fah">
                <i class="fa-solid fa-droplet"></i>
                <h2>HIỆN THỊ NHIỆT ĐỘ THEO ĐỘ F:
                    <span id="nhietdoFs">0</span>°F

                </h2>

            </div>
            <div class="humi">
                <i class="fa-solid fa-percent"></i>
                <h2>HIỆN THỊ ĐỘ ẨM:
                    <span id="doams">0</span>%


                </h2>
            </div>

            <div class="soid">
                <i class="fa-solid fa-land-mine-on"></i>
                <h2>HIỆN THỊ ĐỘ ẨM ĐẤT:
                    <span id="doamdats">0</span>%
                </h2>
            </div>



            <div class="light">
                <i class="fa-regular fa-sun"></i>
                <h2>TÌNH HÌNH ÁNH SÁNG:
                    <span id="anhsangs">0</span>
                </h2>
            </div>

        </div>









    </div>






    <div class="setting">


        <div id="toast">

            <h1 id="intro">THIẾT LẬP ĐIỀU KHIỂN TỰ ĐỘNG</h1>
            <div class="slidecontainer">
                <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my0">
                <p id="quay">NHIỆT ĐỘ: <span id="demo0"></span><span id="do"> °C</span></p>
            </div>

            <div class="slidecontainer">
                <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my2">
                <p id="quay">ĐỘ ẨM ĐẤT: <span id="demo2"></span><span id="do"> %</span></p>
            </div>

            <div class="container">
                <div id="toggle" class="toggle">
                    <div id="toggle_button" class="toggle-button" onclick="Animatedtoggle()"></div>
                </div>
                <div class="text">AUTOMATIC</div>
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




    <div id="change_img" class="modal">
        <div class="modal__overlay"></div>

        <div class="modal__body">


            <!--login form-->
            <div class="auth-form">
                <div class="auth-form__container">
                    <div class="auth-form__header">
                        <h3 class="auth-form__heading"><i
                                style="color: rgb(130, 201, 24); font-size: 24px; margin: 2px 5px auto -12px; "
                                class="fa-regular fa-image"></i> Thay đổi hình nền</h3>

                    </div>
                    <div class="auth-form__form">
                        <div class="auth-form__group">
                            <input type="text" class="auth-form__input" placeholder="Link hình nền của bạn">
                        </div>


                        <!-- <div class="auth-form__group">
                          <input type="password" class="auth-form__input" placeholder="Mật khẩu của bạn">
                      </div>-->
                    </div>


                    <div class="auth-form__controls">

                        <button id="btnXN" class="btnXN btn--primary">XÁC NHẬN</button>

                    </div>
                </div>
            </div>

        </div>
    </div>

    <div id="select">

        <i id="select_img" style="color: rgb(130, 201, 24); font-size: 40px;" class="fa-regular fa-image"></i>
        <p>Select img</p>

    </div>











  <script>


        var nhietdo;
        var doam;
        var doamdat;


        var thoigian = [];
        var giatri = [];

        var giatri_2 = [];

        var giatri_3 = [];

        var toggle = document.querySelector(".toggle");
        var text = document.querySelector(".text");


        var bieudo = document.getElementById("myChart").getContext('2d');

        var image;
        var inputElement = document.querySelector('input[type="text"]');
        var html = document.querySelector('html');
        var buttonXN = document.getElementById("btnXN");

        var change_img = document.getElementById("change_img");

        var select_img = document.getElementById('select_img');
        console.log(buttonXN);

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





        inputElement.onchange = function (e) {

console.log(e.target.value);

image = e.target.value;

console.log(typeof image);
}

buttonXN.onclick = function () {

if (image.includes(".png") || image.includes(".jpg")) {
  console.log("in ra");
  html.style.background = `url(${image})`;
  change_img.style.display = "none";
  change_image();



}
else {
  alert("vui long nhan lai link");
}

}

select_img.onclick = function () {
document.getElementById('change_img').style.display = "flex";
}

function change_image() {
html.style.backgroundRepeat = "no-repeat";
html.style.backgroundSize = "contain";
html.style.backgroundPosition = "center";
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



function Animatedtoggle() {
toggle.classList.toggle("active");

if (toggle.classList.contains("active")) {
  text.innerHTML = "MANUAL";
}
else {
  text.innerHTML = "AUTOMATIC ";
}
}

function getControl() {
if (control == 1) {
  document.getElementById("toggle").style.background = "linear-gradient(135deg, #e1e822, #1eb3c7)";
  document.getElementById("toggle_button").style.left = "20px";
}
else {

}
}
        



  </script>
</body>

</html>
)=====";
