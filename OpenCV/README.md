## MacOS + VSCode 环境下安装 OpenCV

### 安装 OpenCV
有两种方式安装。

#### 1. brew install
```
brew install opencv3
```
安装好之后配置环境变量（命令行会进行提示）
```
export PATH="/usr/local/opt/opencv@3/bin:$PATH"

export LDFLAGS="-L/usr/local/opt/opencv@3/lib"
export CPPFLAGS="-I/usr/local/opt/opencv@3/include"

export PKG_CONFIG_PATH="/usr/local/opt/opencv@3/lib/pkgconfig"
```
> 用homebrew安装很方便，就是安装时间很长，且有可能因为各种原因安装失败。

#### 2. 编译安装
##### 下载源码
[点击这里](https://opencv.org/releases/)下载源代码，这里使用的是 Sources 3.4.5
##### 解压文件
对于 *.tar.gz 文件：
```
tar zxvf opencv-3.4.5.tar.gz
cd opencv-3.4.5
```
对于 *.zip 文件：
```
unzip opencv-3.4.5.zip
cd opencv-3.4.5
```
##### 开始安装
```
cd <opencv 解压后目录>
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make -j8
sudo make install
```
所有的opencv library，就在/Users/your_user_name/opencv/opencv-3.4.0/build/lib中了。
> 一般都不会出问题，在虚拟环境不一定能成功。
参考自 [编译安装opencv](http://wiki.opencv.org.cn/index.php/%E6%BA%90%E7%A0%81%E7%BC%96%E8%AF%91)

### 写个OpenCV Demo
#### pkg-config 环境配置
安装好后，配置一个环境变量就行了。
```
PKG_CONFIG_PATH="~/opencv解压目录/release/unix-install"
PKG_CONFIG_PATH="/Users/bytedance/Documents/package/opencv-3.4.12/build/unix-install"
```
配置好之后在执行命令：
```
pkg-config opencv --libs --cflags opencv
```
