Pod::Spec.new do |s|
  s.name     = 'BaiduMap'
  s.version  = '2.2.1'
  s.summary  = 'The iOS SDK for Baidu Map.'
  s.homepage = 'https://github.com/jcccn/Baidu-Map-SDK-iOS'
  s.author   = { 'Chuncheng Jiang' => 'jccuestc@gmail.com' }
  s.license  = { :type => 'Copyright', :text => <<-LICENSE
                   ©2014 Baidu
                 LICENSE
               }
  s.source   = { :git => 'https://github.com/jcccn/Baidu-Map-SDK-iOS.git', :tag => '2.2.1' }
  s.source_files = "BaiduMap/*.{h,m}"
  s.platform     = :ios, '4.3'
  s.frameworks   = "UIKit", "CoreLocation", "QuartzCore", "OpenGLES", "SystemConfiguration", "CoreGraphics", "Security"
  s.vendored_libraries = 'BaiduMap/libbaidumapapi.a'
  s.resources = 'BaiduMap/mapapi.bundle'
  s.requires_arc = true
end
