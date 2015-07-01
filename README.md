Baidu-Map-SDK-iOS
=================

这是一个 [百度地图 iOS 版本 SDK](http://developer.baidu.com/map/index.php?title=iossdk) 的一个非官方镜像。 

官方开发指南在这里：[http://developer.baidu.com/map/index.php?title=iossdk/guide/introduction](http://developer.baidu.com/map/index.php?title=iossdk/guide/introduction).

百度地图 iOS SDK是一套基于iOS 5.0及以上版本设备的应用程序接口，不仅提供展示地图的基本接口，还提供POI检索、路径规划、地图标注、离线地图、定位、周边雷达等丰富的LBS能力 。

您可以使用百度地图iOS SDK开发适用于移动设备的地图应用，通过接口，您可以轻松访问百度服务和数据，构建功能丰富、交互性强的地图应用程序。

该套SDK提供的服务是免费的，任何非营利性程序均可使用，您需要先 [申请密钥（key）](http://developer.baidu.com/map/ios-mobile-apply-key.htm) ，才可使用该套SDK接口。任何非营利性产品请直接使用，商业目的产品使用前请参考 [使用须知](http://developer.baidu.com/map/index.php?title=open/question) 。

在您使用百度地图iOS SDK之前，请先阅读 [百度地图API使用条款](http://developer.baidu.com/map/index.php?title=open/law) 。

### 功能介绍
1. 地图：提供地图展示和地图操作功能
	- 地图展示包括：普通地图（2D，3D）、卫星图和实时交通图；
	- 地图操作：可通过接口或手势控制来实现地图的点击、双击、长按、缩放、旋转、改变视角等操作。
	
	<img src="http://developer.baidu.com/map/static/img/ios1.jpg" alt="ios1.jpg">
	
2. POI检索：支持周边检索、区域检索、城市内检索和Place详情信息检索。
	- 周边检索：以某一点为中心，指定距离为半径，根据用户输入的关键词进行POI检索；
	- 区域检索：在指定的矩形区域内、根据关键词进行POI检索；
	- 城市内检索：在某一城市内，根据用户输入的关键字进行POI检索；
	- Place详情检索：根据POI的ID信息，检索指定POI点的Place详情数据。
	
	<img src="http://developer.baidu.com/map/static/img/ios2.jpg" alt="ios2.jpg">
	
3. 地理编码：提供地理坐标和地址之间相互转换的能力。
	- 正向地理编码：实现了将中文地址或地名描述转换为地球表面上相应位置的功能；
	- 反向地理编码：将地球表面的地址坐标转换为标准地址的过程。
	
	<img src="http://developer.baidu.com/map/static/img/ios3.jpg" alt="ios3.jpg">
	
4. 线路规划：支持公交信息查询、公交换乘查询、驾车线路规划和步行路径检索。
	- 公交信息查询：可对公交详细信息进行查询；
	- 公交换乘查询：根据起、终点，查询策略，进行线路规划方案；
	- 驾车线路规划：提供不同策略，规划驾车路线；（支持设置途经点）
	- 步行路径检索：支持步行路径的规划。
	
	<img src="http://developer.baidu.com/map/static/img/ios4.jpg" alt="ios4.jpg">
	
5. 覆盖物图层：支持多种覆盖物图层，便于显示POI检索结果、线路规划结果、自定义标绘等。 此外还提供特有的图片图层，用于显示用户传入的图片信息。开放热力图绘制能力，通过用户自有数据，绘制属于自己的热力图。

	<img src="http://wiki.lbsyun.baidu.com/cms/iossdk/img/ios5.png" alt="ios5.png">
	
6. 定位：采用iOS系统定位，使用地图SDK中我的位置图层进行丰富的位置展示（包括普通态、跟随态和罗盘态）。

	<img src="http://developer.baidu.com/map/static/img/ios6.jpg" alt="ios6.jpg">
	
7. 离线地图：用户可以通过手动和SDK接口两种形式导入离线地图包，使用离线地图可节省用户流量，提供更好的地图展示效果。

	<img src="http://wiki.lbsyun.baidu.com/cms/iossdk/img/ios7.jpg" alt="ios7.jpg">
	
8. 调启百度地图：利用SDK接口，直接在本地打开百度地图客户端或WebApp，实现地图功能。 目前支持调启的功能有：POI周边检索、POI详情页面、步行线路规划、驾车线路规划、公交线路规划、驾车导航。（具体请参考开发指南中，计算工具章节内的介绍）

	<img src="http://wiki.lbsyun.baidu.com/cms/iossdk/img/iOS%E8%B0%83%E5%90%AF%E7%99%BE%E5%BA%A6%E5%9C%B0%E5%9B%BE.png" alt="iOS%E8%B0%83%E5%90%AF%E7%99%BE%E5%BA%A6%E5%9C%B0%E5%9B%BE.png">
	
9. 周边雷达：周边雷达功能，是面向移动端开发者的一套SDK功能接口。同步支持Android和iOS端。它的本质是一个连接百度LBS开放平台前端SDK产品和后端LBS云的中间服务。开发者利用周边雷达功能，可以便捷的在自己的应用内，帮助用户实现查找周边跟“我”使同样一款App的人，这样一个功能。

	<img src="http://wiki.lbsyun.baidu.com/cms/iossdk/img/iOS%E5%91%A8%E8%BE%B9%E9%9B%B7%E8%BE%BE.png" alt="iOS%E5%91%A8%E8%BE%B9%E9%9B%B7%E8%BE%BE.png">

10. LBS云：百度地图LBS云是百度地图针对LBS开发者全新推出的平台级服务，不仅适用PC应用开发，同时适用移动设备应用的开发。 使用LBS云，可以实现移动开发者存储海量位置数据的服务器零成本及维护压力，且支持高效检索用户数据，且实现地图展现。

	<img src="http://wiki.lbsyun.baidu.com/cms/iossdk/img/ios9.jpg" alt="ios9.jpg">

11. 特色功能：特色功能包括：短串分享、Place详情检索等。
	- 短串分享：将POI搜索结果或反地理编码结果生成短串，当其他用户点击短串即可打开手	- 机上的百度地图客户端或者手机浏览器进行查看。
	- 热力图绘制：根据用户自有数据，提供相应绘制接口，实现热力图本地绘制；
	- Place详情检索：根据POI的ID信息，检索指定POI点的Place详情数据。
	<img src="http://developer.baidu.com/map/static/img/ios10.jpg" alt="ios10.jpg">