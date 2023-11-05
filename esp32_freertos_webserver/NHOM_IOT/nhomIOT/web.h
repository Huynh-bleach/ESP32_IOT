const char MAIN_page[] PROGMEM = R"=====(<!DOCTYPE html>

<html>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="E:\HTML-CSS\assets\fonts/fontawesome-free-6.2.0-web/css/all.css">

    <script src="https://kit.fontawesome.com/251dd34c64.js" crossorigin="anonymous"></script>
    <link rel="icon" href="https://luv.vn/wp-content/uploads/2021/09/tranh-ve-phong-canh-ha-noi-17-1.jpg"
        type="image/x-icon" />
    <script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.4/Chart.js"></script>
    <title>AGRICULTURAL SUPERVISION</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/8.0.1/normalize.min.css">
    <script src="https://cdn.rawgit.com/Mikhus/canvas-gauges/gh-pages/download/2.1.7/radial/gauge.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/javascript-canvas-to-blob/3.29.0/js/canvas-to-blob.min.js"></script>
   

</head>


<body>






    <div id="home" class="tab-pane active">

        <div class="wordart italic-outline"><span class="text">UPDATE ON THE SITUATION IN THE GREENHOUSE</span></div>


        <div class="content">
            <div class="temp">
                <i class="fa-solid fa-temperature-half"></i>
                <h2>TEMPERATURE DISPLAY:
                    <span id="nhietdos">0</span>°C
                </h2>

            </div>
            <div class="fah">
                <i class="fa-solid fa-droplet"></i>
                <h2>TEMPERATURE DISPLAY IN DEGREES F:
                    <span id="nhietdoFs">0</span>°F

                </h2>

            </div>
            <div class="humi">
                <i class="fa-solid fa-percent"></i>
                <h2>HUMIDITY DISPLAY:
                    <span id="doams">0</span>%

                </h2>
            </div>

            <div class="soid">
                <i class="fa-solid fa-land-mine-on"></i>
                <h2>SOIL MOISTURE DISPLAY:
                    <span id="doamdats">0</span>%
                </h2>
            </div>

            <div class="light">
                <i class="fa-regular fa-sun"></i>
                <h2>LIGHT SITUATION:
                    <span id="anhsangs">0</span>
                </h2>
            </div>

        </div>

        <div  id="gauges_canvas" >

            <canvas id="temp_gauges" data-type="radial-gauge" data-value="0" data-width="300" data-height="300"
                data-bar-width="10" data-bar-shadow="5" data-color-bar-progress="red" data-bar-start-position="left"
                data-title="TEMPERATURE" data-units="°C" data-color-title="red" data-color-units="red"
                data-color-value-box-rect="red" data-color-border-outer="red" data-font-value="Led"
                data-font-numbers="Led" data-font-title="Led" data-font-units="Led" data-font-numbers-size="25"
                data-font-value-size="30" data-font-title-size="30" data-font-units-size="30"
                data-font-title-weight="900" data-font-value-weight="900"></canvas>

            <canvas id="fah_gauges" data-type="radial-gauge" data-value="0" data-width="300" data-height="300"
                data-bar-width="10" data-bar-shadow="5" data-color-bar-progress="blue" data-bar-start-position="left"
                data-title="TEMPERATURE F" data-units="°F" data-color-title="blue" data-color-units="blue"
                data-color-value-box-rect="blue" data-color-border-outer="blue" data-color-value="blue"
                data-font-value="Led" data-font-numbers="Led" data-font-title="Led" data-font-units="Led"
                data-font-numbers-size="25" data-font-value-size="30" data-font-title-size="30"
                data-font-units-size="30" data-font-title-weight="900" data-font-value-weight="900"></canvas>

            <canvas id="humi_gauges" data-type="radial-gauge" data-value="0" data-width="300" data-height="300"
                data-bar-width="10" data-bar-shadow="5" data-color-bar-progress="green" data-bar-start-position="left"
                data-title="HUMIDITY" data-units="%" data-color-title="green" data-color-units="green"
                data-color-value-box-rect="green" data-color-border-outer="green" data-font-value="Led"
                data-font-numbers="Led" data-font-title="Led" data-font-units="Led" data-font-numbers-size="25"
                data-font-value-size="30" data-font-title-size="30" data-font-units-size="30"
                data-font-title-weight="900" data-font-value-weight="900"></canvas>

            <canvas id="soid_gauges" data-type="radial-gauge" data-value="0" data-width="300" data-height="300"
                data-bar-width="10" data-bar-shadow="5" data-color-bar-progress="brown" data-bar-start-position="left"
                data-title="SOIL MOISTURE" data-units="%" data-color-title="brown" data-color-units="brown"
                data-color-value-box-rect="brown" data-color-border-outer="brown" data-font-value="Led"
                data-font-numbers="Led" data-font-title="Led" data-font-units="Led" data-font-numbers-size="25"
                data-font-value-size="30" data-font-title-size="30" data-font-units-size="30"
                data-font-title-weight="900" data-font-value-weight="900"></canvas>

            <canvas id="light_gauges" data-type="radial-gauge" data-value="0" data-width="300" data-height="300"
                data-minor-ticks="10" data-bar-width="10" data-bar-shadow="5" data-color-bar-progress="orange"
                data-bar-start-position="left" data-title="LIGHT" data-units="%" data-color-title="orange"
                data-color-units="orange" data-color-value-box-rect="orange" data-color-border-outer="orange"
                data-font-value="Led" data-font-numbers="Led" data-font-title="Led" data-font-units="Led"
                data-font-numbers-size="25" data-font-value-size="30" data-font-title-size="30"
                data-font-units-size="30" data-font-title-weight="900" data-font-value-weight="900"></canvas>
        </div>

    </div>



    <div class="tab-pane" id="chart" style="text-align: center; align-items: center; max-height: 550px;">
        <canvas id="myChart" style="height: 500px;"></canvas>
    </div>

    <div id="toast" class="tab-pane">

        <h1 id="intro">SET UP AUTOMATIC CONTROL</h1>
        <div class="slidecontainer">
            <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my0">
            <p id="quay">LED BRIGHTNESS: <span id="demo0"></span><span id="do"> %</span></p>
        </div>

        <div class="slidecontainer">
            <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my2">
            <p id="quay">FAN SPEED: <span id="demo2"></span><span id="do"> %</span></p>
        </div>

        <div class="slidecontainer">
            <input type="range" min="0" max="100" value="0" class="slid slid_change" id="my3">
            <p id="quay">PUMP SPEED: <span id="demo3"></span><span id="do"> %</span></p>
        </div>

        <div id="container">
            <div id="toggle">
                <div id="toggle_button"></div>
                <div class="text"></div>
            </div>
        </div>

        <div class="nutnhan" id="button_media_on">
            <div class="led" id="led" title="1">
                <div id="ledcontrol" class="btn btn_on">
                    <div class="btn_1">
                        <div id="toggle_control" onclick="control_button(0,'LED')"></div>
                        <div id="text_led">OFF LED</div>
                    </div>
                </div>
            </div>


            <div class="fan" id="fan" title="1">
                <div id="ledcontrol" class="btn btn_on">
                    <div class="btn_1">
                        <div id="toggle_control" onclick="control_button(1,'FAN')"></div>
                        <div id="text_led">OFF FAN</div>
                    </div>
                </div>
            </div>


            <div class="pump" id="pump" title="1">
                <div id="ledcontrol" class="btn btn_on">
                    <div class="btn_1">
                        <div id="toggle_control" onclick="control_button(2,'PUMP')"></div>
                        <div id="text_led">OFF PUMP</div>
                    </div>
                </div>
            </div>
        </div>


        <div class="nutnhan" id="button_media_off" style="display: none;">
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

    <div class="tab-pane">
    </div>




    <div id="icon_bar">
        <div id="baricon">
            <i class="fa-solid fa-bars"></i>
        </div>
    </div>
    <div id="task_mobile">
        <div class="tabs">
            <img class="img_bar" src="https://luv.vn/wp-content/uploads/2021/09/tranh-ve-phong-canh-ha-noi-17-1.jpg">
            <h3>USER NAME</h3>
            <div id="icon_home" class="tab-item active">
                <i class="fa-sharp fa-solid fa-house"></i>
                <h4>Home</h4>

            </div>

            <div id="icon_chart" class="tab-item">
                <i class="fa-sharp fa-solid fa-chart-line"></i>
                <h4>Chart</h4>

            </div>

            <div id="icon_setting" class="tab-item">
                <i class="fa-sharp fa-solid fa-gear"></i>
                <h4>Setting</h4>
            </div>

            <div id="icon_video" class="tab-item">
                <i class="fa-solid fa-video"></i>
                <h4>Video</h4>

            </div>
            <div class="line"></div>
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
        var samplingTime = 10000;
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
        var valiable = 0;
        var button_control = document.getElementById('toggle_button');
        var text_control = document.querySelector('.text');
        var idcontrol = document.getElementById("toggle");

        var ledcontrol = document.querySelectorAll("#ledcontrol");
        console.log(buttonXN);

        getkiemtraNT();
        getkiemtraDAD();
        getkiemtraTime();

        getControl();
        getImage("https://haycafe.vn/wp-content/uploads/2021/12/Download-hinh-nen-anime-cho-desktop-thanh-pho-duoi-trang.jpg");

        // getControl()
        setInterval(function () {
            // Call a function repetatively with 2 Second interval
            getnhietdo();
            getnhietdoF();
            getdoam();
            //------------------
            getdoamdat();
            getanhsang();

        }, 1000); //2000mSeconds update rate


        function getkiemtraTime() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {

                    document.getElementById("my3").value = this.responseText;
                    document.getElementById("demo3").innerHTML = this.responseText;
                    console.log(typeof this.responseText);
                    console.log(this.responseText);

                }
            };
            xhttp.open("GET", "kiemtraTime", true);
            xhttp.send();
        }

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

        function getControl() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {




                    if (this.responseText == "1") {
                        button_control.className = 'toggle-on';
                        text_control.className = 'text-on';
                        text_control.textContent = "AUTOMATIC"
                        button_control.setAttribute('onclick', 'Toggle_CHECK()');
                        idcontrol.style.background = 'linear-gradient(135deg, #ff3300, #86d472)';
                        update_control_button("none");

                    }

                    else {

                        button_control.className = 'toggle-off';
                        text_control.className = 'text-off';
                        text_control.textContent = "MANUAL";
                        button_control.setAttribute('onclick', 'Toggle_CHECK()');
                        idcontrol.style.background = 'linear-gradient(135deg, #e1e822, #1eb3c7)';
                        update_control_button("flex");


                    }

                }
            };
            xhttp.open("GET", "kiemtraCONTROL", true);
            xhttp.send();
        }

        function getImage() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {

                    image = this.responseText;
                    html.style.background = `url(${this.responseText})`;
                    change_img.style.display = "none";
                    if (window.outerWidth < 785) {
                        change_image_mobile();
                    }
                    else {
                        change_image();
                    }

                }
            };
            xhttp.open("GET", "kiemtraIMAGE", true);
            xhttp.send();


        }

        function getnhietdo() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("nhietdos").innerHTML = this.responseText;

                    document.getElementById('temp_gauges').setAttribute('data-value', `${this.responseText}`);
    

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

                    document.getElementById('fah_gauges').setAttribute('data-value', `${this.responseText}`);
   


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
                    document.getElementById('humi_gauges').setAttribute('data-value', `${this.responseText}`);
    

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

                    document.getElementById('soid_gauges').setAttribute('data-value', `${this.responseText}`);
   
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
                    document.getElementById('light_gauges').setAttribute('data-value', `${this.responseText}`);

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




        }, samplingTime);



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

        }, samplingTime)



        setInterval(function () {

            var line_chart = new Chart(bieudo, {
                type: "line",
                data: {
                    labels: thoigian,
                    datasets: [{
                        label: 'Temperature',
                        fill: false,
                        lineTension: 0,
                        backgroundColor: "rgba(205,0,0,1.0)",
                        borderColor: "rgba(205,0,0,0.5)",
                        data: giatri,
                        tension: 0.3,
                        borderWidth: 6
                    },
                    {
                        label: 'Humidity',
                        fill: false,
                        lineTension: 0,
                        backgroundColor: "rgba(0,205,0,1.0)",
                        borderColor: "rgba(0,205,0,0.5)",
                        data: giatri_2,
                        tension: 0.3,
                        borderWidth: 6

                    },
                    {
                        label: 'Soil moisture',
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
                        text: 'Agricultural Monitoring Chart',
                        fontSize: 25,
                    },
                    scales: {
                        yAxes: [{ ticks: { min: 0, max: 100 } }],
                    },
                }
            });


        }, samplingTime)
        const $ = document.querySelector.bind(document); // dinh nghia ra de su dung
        const $$ = document.querySelectorAll.bind(document);// lay ra nhieu thang

        const tabs = $$(".tab-item");
        const panes = $$(".tab-pane");

        const tabActive = $(".tab-item.active");
        const line = $(".tabs .line");

        // SonDN fixed - Active size wrong size on first load.
        // Original post: https://www.facebook.com/groups/649972919142215/?multi_permalinks=1175881616551340
        requestIdleCallback(function () {
            line.style.bottom = "161px";
            line.style.width = tabActive.offsetWidth + "px";
        });




        tabs.forEach((tab, index) => {
            const pane = panes[index];

            tab.onclick = function () {
                $(".tab-item.active").classList.remove("active");
                $(".tab-pane.active").classList.remove("active");
                if (screen.width < 740) {
                    document.getElementById("task_mobile").style.display = "none";

                }

                console.log(typeof this);

                const transmit = this.textContent;

                console.log(typeof transmit);
                console.log(transmit);

                if (transmit.includes("Chart")) {
                    line.style.bottom = "110px";
                }
                else if (transmit.includes(" Setting")) {
                    line.style.bottom = "54px";
                }

                else if (transmit.includes("Video")) {
                    line.style.bottom = "0px";
                }
                else {
                    line.style.bottom = "161px";
                }


                line.style.width = this.offsetWidth + "px";

                this.classList.add("active");
                pane.classList.add("active");
            };
        });


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
        /*
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
        */
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
                Sendata_image(image);

            }
            else {
                alert("vui long nhan lai link");
            }

        }

        select_img.onclick = function () {
            document.getElementById('change_img').style.display = "flex";
        }




        var icon_bar = document.getElementById("baricon");
        console.log(icon_bar);

        icon_bar.onclick = function () {
            document.getElementById("task_mobile").style.display = "block";
        };






        function change_image() {
            html.style.backgroundRepeat = "no-repeat";
            html.style.backgroundSize = "contain";
            html.style.backgroundPosition = "center";
        }

        function change_image_mobile() {
            html.style.height = "100%";
            html.style.backgroundSize = "auto 100%";
            html.style.backgroundRepeat = "no-repeat";
            html.style.backgroundPosition = "center";
        }


        function Sendata_image(img) {
            console.log("link hinh anh la: ", img);
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    console.log(this.responseText);
                }
            };
            xhttp.open("GET", "setIMAGE?IMAGE=" + img, true);
            xhttp.send();
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

        function sendData_TIME(pos) {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    console.log(this.responseText);
                }
            };
            xhttp.open("GET", "setTIME?TIME=" + pos, true);
            xhttp.send();
        }
        var s3 = document.getElementById("my3");
        var o3 = document.getElementById("demo3");
        o3.innerHTML = s3.value;

        s3.oninput = function () {
            o3.innerHTML = this.value;
            sendData_TIME(o3.innerHTML);
        }

        function button() {
            document.getElementById("toast").style.display = "none";


        }


        function click_icon() {
            document.getElementById("toast").style.display = "block";


        }

        function Toggle_CHECK() {
            var check = button_control.classList.contains('toggle-on');

            if (check) {
                button_control.classList.remove('toggle-on');
                text_control.classList.remove('text-on');
                button_control.setAttribute('class', 'toggle-off');
                text_control.setAttribute('class', 'text-off');
                text_control.textContent = "MANUAL"
                idcontrol.style.background = 'linear-gradient(135deg, #e1e822, #1eb3c7)';
                update_control_button("flex");
                Sendata_control("0");

            }
            else {
                button_control.classList.remove('toggle-off');
                text_control.classList.remove('text-off');
                button_control.setAttribute('class', 'toggle-on');
                text_control.setAttribute('class', 'text-on');
                text_control.textContent = "AUTOMATIC"
                idcontrol.style.background = 'linear-gradient(135deg, #ff3300, #86d472)';
                update_control_button("none");
                Sendata_control("1");

            }
        }


        function Sendata_control(val) {
            console.log("Gia tri nhan duoc la: ", val);
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    console.log(this.responseText);
                }
            };
            xhttp.open("GET", "setCONTROL?CONTROL=" + val, true);
            xhttp.send();
        }

        function update_control_button(signal) {

            document.getElementById("button_media_on").style.display = signal;
            //document.getElementById("button_media_off").style.display = signal;

        }



        var icon_bar = document.getElementById("baricon");
        console.log("hienj thi len");
        console.log(icon_bar);


        icon_bar.onclick = function () {
            document.getElementById("task_mobile").style.display = "block";
        };




        var sendcontrol = document.getElementById("toggle_control");



        function control_button(val, title) {
            console.log('dang su dung:', val, 'vaf title la:', title);

            if (document.querySelectorAll("#toggle_control")[val].style.order == "0") {
                mode_button_control_OFF(val, title)
                console.log("OFF");
                select_button_control(0, title);


            }
            else {
                mode_button_control_ON(val, title)
                console.log("ON");
                select_button_control(1, title);

            }
        }

        function select_button_control(number, property) {
            if (property == "LED") {
                console.log("TIEN HANH DIEU KHIEN l ", property);
                console.log("DANG O TRANG THAI: ", number);
                sendData_LED(number);
            }
            else if (property == "FAN") {
                console.log("TIEN HANH DIEU KHIEN f ", property);
                console.log("DANG O TRANG THAI: ", number);
                sendData_FAN(number);
            }
            else {
                console.log("TIEN HANH DIEU KHIEN  p ", property);
                console.log("DANG O TRANG THAI: ", number);
                sendData_PUMP(number);
            }
        }

        function mode_button_control_OFF(val, title) {
            document.querySelectorAll("#text_led")[val].style.order = '0';
            document.querySelectorAll("#toggle_control")[val].style.order = '1';
            document.querySelectorAll("#text_led")[val].innerHTML = `OFF ${title}`;
            ledcontrol[val].style.backgroundImage = "linear-gradient(135deg, #e1e822, #1eb3c7)";
        }

        function mode_button_control_ON(val, title) {
            document.querySelectorAll("#toggle_control")[val].style.order = '0';
            document.querySelectorAll("#text_led")[val].style.order = '1';
            document.querySelectorAll("#text_led")[val].innerHTML = `ON ${title}`;
            ledcontrol[val].style.backgroundImage = "linear-gradient(135deg, #E83507, #86d472)";
        }

        function displayWindowSize() {
            if (window.outerWidth < 785) {
                console.log("Thay doi man hinh!");
                html.style.backgroundImage = `url(${image})`;
                change_image_mobile();
            }
        }
        window.onresize = displayWindowSize;

    </script>

<style>
    @media screen and (min-width: 741px) {
        #icon_bar {
            display: none;
        }

        .img_bar {
            display: none;
        }

        .tabs h3 {
            display: none;
        }

        html {
            width: 100%;
            height: 100%;
            /*background-image: url(https://thuthuatnhanh.com/wp-content/uploads/2021/12/Background-cay-xanh-phong-canh-dep.jpg);*/
            background-image: url(https://cdn.sforum.vn/sforum/wp-content/uploads/2022/06/35-2.jpg);
            background-repeat: no-repeat;
            background-size: contain;
            background-position: center;

        }

        #home {
            width: 75%;
            height: 100%;
            margin: 20px auto auto auto;



        }


        .wordart {
            font-family:'Times New Roman', Times, serif;
            font-size: 35px;
            font-weight: bold;
            z-index: 1;
            display: block;
            -webkit-font-smoothing: antialiased;
            -moz-osx-font-smoothing: grayscale;
            margin: auto auto 20px auto;
            align-items: center;
            text-align: center;
        }

        .wordart.italic-outline {
            transform: scale(1, 1.3);
            -webkit-transform: scale(1, 1.3);
            -moz-transform: scale(1, 1.3);
            -o-transform: scale(1, 1.3);
            -ms-transform: scale(1, 1.3);
        }

        .wordart.italic-outline .text {
            letter-spacing: -0.01em;
            font-family:'Times New Roman', Times, serif;
            font-weight: 900;
            color: #fff;
            -webkit-text-stroke: 0.01em #000;
            filter: progid:DXImageTransform.Microsoft.Glow(Color=#000000, Strength=1);
            text-shadow: 0.03em 0.03em 0 #191818;
        }












        #gauges_canvas {
            display: flex;
            flex-wrap: wrap;
            width: 100%;
            height: auto;
            justify-content: space-around;

        }





        .content {
            display: none;
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
            border: 3px solid #1dd2cf;
            border-radius: 4px;
            box-shadow: 2px 4px 5px #053d62;
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
            height: 60px;
            box-sizing: border-box;
            outline: none;
            color: #fff;
            padding: 4px 4px;
            border-radius: 50px;
            margin: auto;
            text-align: center;
            font-size: 25px;
            font-weight: 900;
            z-index: 2;
            box-shadow: 3px 3px 3px 3px #212129;

        }

        /*
#led,
#led1,
#fan,
#fan1,
#pump,
#pump1 {
display: block;
}
*/

        /*  .btn_on {
            background-image: linear-gradient(135deg, #E83507, #86d472);
            display: block;

        }

        .btn_off {

            background-image: linear-gradient(135deg, #e1e822, #1eb3c7);
            display: block;
        }
        */

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

        /*
        .slidecontainer {
            width: 50%;
        }
*/
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

        .tab-item i {
            font-size: 30px;
            color: #0f5209;
            margin-left: 10px;
        }

        .tab-item {
            display: flex;
            text-align: center;
            align-items: center;
            max-width: 135px;
            cursor: pointer;
            height: 50px;
            border-top-left-radius: 5px;
            border-top-right-radius: 5px;
            border-bottom: 5px solid transparent;
            opacity: 0.5;
            cursor: pointer;
            transition: all 0.5s ease;

        }

        .tab-item h4 {
            font-size: 20px;
            margin-left: 10px;
        }

        .tab-item+.tab-item {
            margin-top: 0px;
        }

        .tab-item:hover {
            opacity: 1;
            background-color: rgba(0, 255, 0, 0.15);
            border-color: rgba(0, 255, 0, 0.25);
        }

        .tabs {
            position: absolute;
            width: 135px;
            top: 0px;
            left: 0px;
            background-color: rgba(206, 243, 212, 0.5);
        }


        .tabs .line {
            position: absolute;
            left: 0;
            bottom: 0;
            width: 0;
            height: 6px;
            border-radius: 15px;
            background-color: #064d00;
            transition: all 0.2s ease;
        }

        .tab-item.active {
            opacity: 1;

        }

        .tab-pane {
            display: none;
        }

        .tab-pane.active {
            display: block;
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

        #container {
            height: 50px;
            text-align: center;
            display: flex;
            justify-content: center;
            margin-bottom: 20px;

        }

        #toggle {
            position: relative;
            max-width: 220px;
            min-width: 160px;
            height: 50px;
            border-radius: 30px;
        }

        /* #container .toggle.active {}
*/
        .toggle-off {
            position: absolute;
            top: 2px;
            left: 112px;
            width: 40px;
            height: 40px;
            border: 3px solid #333;
            background: rgb(237, 230, 230);
            border-radius: 50%;
            cursor: pointer;
            z-index: 1;
        }

        .toggle-on {
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

        #toggle .text-on {
            position: relative;
            margin: 10px auto auto 50px;
            font-size: 25px;
            font-family: Arial, Helvetica, sans-serif;

        }

        #toggle .text-off {
            position: relative;
            left: -45px;
            margin: 10px auto auto 50px;
            font-size: 25px;
            font-family: Arial, Helvetica, sans-serif;

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

        #toggle_control {
            width: 40px;
            height: 40px;
            border: 3px solid #333;
            background: rgb(237, 230, 230);
            border-radius: 50%;
            cursor: pointer;
            margin-left: 3px;
            margin-right: 3px;
            order: 1;
        }

        #text_led {
            margin-right: 3px;
            margin-left: 3px;
            order: 0;
        }

        #ledcontrol {
            background-image: linear-gradient(135deg, #e1e822, #1eb3c7);
            display: block;
        }





    }



    @media screen and (max-width: 740px) {

        #tab_pc {
            display: none;
        }

        #select {
            display: none;
        }


        #change_img {
            display: none;
        }


        /* html {
            height: 100%;
            background-image: url(https://images4.alphacoders.com/606/thumb-1920-606667.jpg);
            background-repeat: no-repeat;
            background-position: center;
        }*/

        #task_mobile .tabs {
            animation: slideInLeft linear 0.4s;
            transition: all linear 0.5s;

        }

        #task_mobile {
            display: none;
            animation: fadeIn linear 0.2s;
        }




        .tab-item i {
            font-size: 30px;
            color: #0f5209;
            margin-left: 30px;
        }

        .tab-item {
            display: flex;
            text-align: center;
            align-items: center;
            width: 100%;
            cursor: pointer;
            height: 75px;
            border-top-left-radius: 5px;
            border-top-right-radius: 5px;
            border-bottom: 7.5px solid transparent;
            opacity: 0.5;
            cursor: pointer;
            transition: all 0.5s ease;

        }

        .tab-item h4 {
            font-size: 20px;
            margin-left: 10px;
        }

        .tab-item+.tab-item {
            margin-top: 0px;
        }

        .tab-item:hover {
            opacity: 1;
            background-color: rgba(0, 255, 0, 0.15);
            border-color: rgba(0, 255, 0, 0.25);
        }

        .tabs {
            position: absolute;
            width: 200px;
            height: 100%;
            top: 0px;
            left: 0px;
            background-color: rgba(255, 255, 255);
        }


        .tabs .line {
            position: absolute;
            left: 0;
            bottom: 0;
            width: 0;
            height: 6px;
            border-radius: 15px;
            background-color: #064d00;
            transition: all 0.2s ease;
        }

        .tab-item.active {
            opacity: 1;

        }

        .tab-pane {
            display: none;
        }

        .tab-pane.active {
            display: block;
        }

        #task_mobile {
            position: fixed;
            top: 0;
            right: 0;
            left: 0;
            bottom: 0;
            width: 100%;
            height: 100%;
            background-color: rgba(0, 0, 0, 0.5)
        }

        .img_bar {
            display: block;
            border-radius: 50%;
            width: 50%;
            margin: auto;

        }

        .tabs h3 {
            color: #064d00;
            align-items: center;
            text-align: center;

        }





        @keyframes slideInLeft {
            from {
                opacity: 0;
                transform: translateX(-100%);
            }

            to {
                opacity: 1;
                transform: translateX(0);
            }
        }


        @keyframes slideInRight {
            from {
                opacity: 0;
                transform: translateX(0);
            }

            to {
                opacity: 1;
                transform: translateX(-100%);
            }
        }




        @keyframes fadeIn {
            from {
                opacity: 0;
            }

            to {
                opacity: 1;
            }

        }


        #icon_bar {
            display: block;
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 50px;
            background-color: rgba(206, 243, 212, 0.5);
        }

        #baricon {
            position: relative;
            display: block;
            font-size: 30px;
            top: 8.5px;
            left: 15px;

        }







        #home {
            width: 100%;
            height: auto;


        }

        .wordart {
            font-family:'Times New Roman', Times, serif;
            font-size: 20px;
            font-weight: bold;
            z-index: 1;
            display: block;
            -webkit-font-smoothing: antialiased;
            -moz-osx-font-smoothing: grayscale;
            margin: 65px auto 20px auto;
            align-items: center;
            text-align: center;
        }

        .wordart.italic-outline {
            transform: scale(1, 1.3);
            -webkit-transform: scale(1, 1.3);
            -moz-transform: scale(1, 1.3);
            -o-transform: scale(1, 1.3);
            -ms-transform: scale(1, 1.3);
        }

        .wordart.italic-outline .text {
            letter-spacing: -0.01em;
            font-family:'Times New Roman', Times, serif;
            font-weight: 900;
            color: #fff;
            -webkit-text-stroke: 0.01em #000;
            filter: progid:DXImageTransform.Microsoft.Glow(Color=#000000, Strength=1);
            text-shadow: 0.03em 0.03em 0 #191818;
        }


        .content {
            display: flex;
            flex-wrap: wrap;
            width: 100%;
            height: auto;
        }

        #gauges_canvas{
            display: none;
        }


        .temp,
        .fah,
        .humi,
        .soid,
        .light {

            height: 160px;
            flex-basis: 40%;
            margin: 0px auto 30px auto;
            border-radius: 4px;
            box-shadow: 0 5px 7px #053d62;
            background-color: rgba(206, 243, 212, 0.5);

        }

        .content h2 {
            display: block;
            margin: auto;
            text-align: center;
            font-size: 18px;
        }

        .content i {
            display: block;
            margin: 15px auto;
            align-items: center;
            text-align: center;
            font-size: 30px;
        }


        .temp i,
        .temp h2 {
            color: red;

        }

        .fah i,
        .fah h2 {
            color: blue;

        }

        .humi i,
        .humi h2 {
            color: green;

        }

        .soid i,
        .soid h2 {
            color: brown;

        }

        .light i,
        .light h2 {
            color: orange;

        }

        .temp {
            border: 3px solid red;
        }

        .fah {
            border: 3px solid blue;
        }

        .soid {
            border: 3px solid brown;
        }

        .humi {
            border: 3px solid green;
        }

        .light {
            border: 3px solid orange;
        }



        #myChart {
            display: block;
            width: 90%;
            height: auto;
            border: 5px solid #0f580f;
            border-radius: 3px;
            margin: 70px auto 0px auto;
            background-color: rgba(255, 255, 255, 0.5);
            z-index: -1;
        }





        #container {
            height: 50px;
            text-align: center;
            display: flex;
            justify-content: center;
            margin-bottom: 20px;

        }

        #toggle {
            position: relative;
            max-width: 220px;
            min-width: 160px;
            height: 50px;
            border-radius: 30px;
        }

        /* #container .toggle.active {}
*/
        .toggle-off {
            position: absolute;
            top: 2px;
            left: 112px;
            width: 40px;
            height: 40px;
            border: 3px solid #333;
            background: rgb(237, 230, 230);
            border-radius: 50%;
            cursor: pointer;
            z-index: 1;
        }

        .toggle-on {
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

        #toggle .text-on {
            position: relative;
            margin: 10px auto auto 50px;
            font-size: 25px;
            font-family: Arial, Helvetica, sans-serif;

        }

        #toggle .text-off {
            position: relative;
            left: -45px;
            margin: 10px auto auto 50px;
            font-size: 25px;
            font-family: Arial, Helvetica, sans-serif;

        }



        .container+.nutnhan {
            margin-top: 40px;
        }

        .nutnhan+.nutnhan {
            margin-top: 30px;
        }

        .nutnhan {
            display: flex;
            flex-direction: column;

        }


        .btn {
            min-width: 110px;
            max-width: 205px;
            height: 60px;
            box-sizing: border-box;
            outline: none;
            color: #fff;
            padding: 4px 4px;
            border-radius: 50px;
            margin: auto;
            text-align: center;
            font-size: 25px;
            font-weight: 900;
            z-index: 2;
            box-shadow: 3px 3px 3px 3px #212129;

        }

        #led+#fan {
            margin-top: 15px;
        }

        #fan+#pump {
            margin-top: 15px;
        }

        /*
#led,
#led1,
#fan,
#fan1,
#pump,
#pump1 {
display: block;
}
*/

        /*  .btn_on {
            background-image: linear-gradient(135deg, #E83507, #86d472);
            display: block;

        }

        .btn_off {

            background-image: linear-gradient(135deg, #e1e822, #1eb3c7);
            display: block;
        }
*/
        .btn_on .btn_1,
        .btn_off .btn_1 {

            background: black;
            border-radius: 50px;
            height: 100%;
            transition: background 0.5s ease;
            width: 100%;
            display: flex;
            justify-content: space-around;
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

        /*
        .slidecontainer {
            width: 50%;
        }
        */

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
            width: 95%;
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

            border-radius: 2px;
            padding: 10px 0;
            width: 100%;
            /*border-left: 9px solid #054e11;*/
            box-shadow: 0 7px 12px rgba(5, 7, 0, 0.4);
            transition: all linear 0.3s;
            /*background-color: #fafafa;*/
            align-items: center;
            background-color: rgba(206, 243, 212, 0.5);
            margin: 55px auto auto auto;
            max-height: 700px;
        }

        #toast div {

            text-align: center;
        }

        #intro {
            text-align: center;
            margin: 5px 0px 20px;
            font-size: 25px;
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


        #toggle_control {
            width: 40px;
            height: 40px;
            border: 3px solid #333;
            background: rgb(237, 230, 230);
            border-radius: 50%;
            cursor: pointer;

            order: 1;
        }

        #text_led {

            order: 0;
        }

        #ledcontrol {
            background-image: linear-gradient(135deg, #e1e822, #1eb3c7);
            display: block;
        }






    }
</style>
</body>

</html>
)=====";
