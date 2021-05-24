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
[点击这里](https://opencv.org/releases/)下载源代码，这里使用的是 Sources 3.4.12
解压后，进入目录。
