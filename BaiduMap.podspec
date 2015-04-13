Pod::Spec.new do |s|
  s.name     = 'BaiduMap'
  s.version  = '2.7.0'
  s.summary  = 'The iOS SDK for Baidu Map.'
  s.homepage = 'https://github.com/jcccn/Baidu-Map-SDK-iOS'
  s.author   = { 'Chuncheng Jiang' => 'jccuestc@gmail.com' }
  s.license  = { :type => 'Copyright', :text => <<-LICENSE
                   ©2015 Baidu
                 LICENSE
               }
  s.source   = { :git => 'https://github.com/jcccn/Baidu-Map-SDK-iOS.git', :tag => '2.7.0' }
  s.platform     = :ios, '4.3'
  s.frameworks   = "UIKit", "CoreLocation", "QuartzCore", "OpenGLES", "SystemConfiguration", "CoreGraphics", "Security"
  s.libraries    = 'stdc++'
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }

  s.requires_arc = true

  s.default_subspec = 'All'

  ### 子模块

  # 完整功能的SDK
  s.subspec 'All' do |alls|
    alls.requires_arc = true
    alls.vendored_frameworks = 'BaiduMap/Frameworks/BaiduMapAPI.framework'
  end

  # 基础地图（包括矢量图/卫星图显示、操作及各种地图覆盖物）
  s.subspec 'BaseMap' do |basemaps|
    basemaps.requires_arc = true
    basemaps.vendored_frameworks = 'BaiduMap/Frameworks/BaiduMapAPIBaseMap.framework'
  end

  # 检索功能（包括POI检索、地理编码、线路规划等功能）
  s.subspec 'Search' do |searchs|
    searchs.requires_arc = true
    searchs.vendored_frameworks = 'BaiduMap/Frameworks/BaiduMapAPISearch.framework'
  end

  # LBS云检索（支持检索用户LBS云内的自有数据）
  s.subspec 'CloudSearch' do |cloudsearchs|
    cloudsearchs.requires_arc = true
    cloudsearchs.vendored_frameworks = 'BaiduMap/Frameworks/BaiduMapAPICloudSearch.framework'
  end

  # 定位功能（提供便捷接口，获取当前位置信息）
  s.subspec 'Location' do |locations|
    locations.requires_arc = true
    locations.vendored_frameworks = 'BaiduMap/Frameworks/BaiduMapAPILocation.framework'
  end

  # 计算工具（包括计算距离、坐标转化、调启导航等能力）
  s.subspec 'Utils' do |utilss|
    utilss.requires_arc = true
    utilss.vendored_frameworks = 'BaiduMap/Frameworks/BaiduMapAPIUtils.framework'
  end

end
