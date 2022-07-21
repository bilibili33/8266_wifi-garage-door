# 8266_wifi-garage-door

## 用的blinker

把开头三行东西填了
* auth 是 设备秘钥
* ssid 是 wifi名称
* pswd 是 wifi密码

点灯的app上要四个按钮和一个标签
* 上行按钮名称是 btn-1
* 下行按钮名称是 btn-2
* 暂停按钮名称是 btn-3
* 防误触锁名称是 btn-lock
* 文本框的名称是 tex-1

然后把 btn-lock 的类型改了，改成开关式的<br>
按钮位置随便摆，按着舒服就行

板子是nodemcu，就是自带串口芯片的那个版本<br>
用的 GPIO 是 5,4,14
* 上行接D1(GPIO5)
* 下行接D2(GPIO4)
* 暂停接D5(GPIO14)

误触锁延时 30s<br>
按上下行时会先触发暂停，算是对传统遥控器在卷帘门动作时直接按上下行没反应的一个小优化（？）<br>
接线的话可以接按钮盒里，不过我还没量电压，超3v的话要用三个继电器<br>
- - -
成本的话
* 一个 nodemcu esp8266 大概 12 rmb
* 一个 4 路的 5v 继电器板大概 12 rmb ，注意一定要选高电平触发的版本（买到黑板的只能低电平触发，给我整麻了，又去特意找了个红板的）

- - -
### 后续
拆家拆完了，量过小铁盒的按钮开关了，只能用继电器（只会用继电器（√））<br>
然后停止按钮接的是常闭触点，意味着不能和小铁盒的按钮并联。<br>
停止按钮要正常工作的话只能把小铁盒的那路线掐了，不想掐的话可以装个普通灯的那种开关（虽然我估计装完后完全不会去动就是了）<br>

继电器选取和连线说人话就是
买个能高电平触发的版本，信号输入按上面的说明接好，把电闸拉了，把手动按钮铁盒线从中间剪了，拆开铁盒看看对应的线，把除了往小铁盒方向的停止线之外的线都各自对应拧好，线上行和下行都是接继电器的的NO上，停止接NC上，三个COM串在一起接公共线

看不懂文字就看图吧。。画了个示意图
