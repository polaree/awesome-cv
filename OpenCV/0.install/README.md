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
rm ../CMakeCache.txt
cmake ..
make -j8
sudo make install
```
所有的opencv library，就在 opencv解压目录/build/lib 中了。
> 一般都不会出问题，在虚拟环境不一定能成功。

这里请保存下 opencv 解压后目录，后面需要用到。如：/Users/bytedance/Documents/package/opencv-3.4.5

### 写个C++ Hello World
```
#include <stdio.h>
#include <iostream>

int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    return 0;
}
```
如果能够成功输出 Hello, world! 就尝试在代码中引入 OpenCV 库。

### pkg-config 环境配置
安装好后，配置一个环境变量就行了。
```
PKG_CONFIG_PATH="opencv解压目录/build/unix-install"
```
配置好之后在执行命令：
```
pkg-config opencv --libs --cflags opencv
```
> 该环境变量就是为了让 pkg-config 能够找到 opencv.pc 这个文件。

### 写个OpenCV Demo
进入到命令行环境
```
## 编译测试程序
g++ `pkg-config opencv --libs --cflags opencv` ./test.cpp -o ./test.o
## 运行测试程序
./test.o
```
> pkg-config 这条命令是为编译 opencv 测试代码引入类库。
> 如果能够成功显示图片，则代表 opencv 已经安装成功了。

为了避免重复输入命令，我们在根目录下创建一个.vocode文件夹，再创建一个 task.json 文件。
- .vscode/tasks.json

文件内容为：
```
{
    "tasks": [
        {
            "type": "shell",
            "label": "g++ build active file",
            "command": "/usr/bin/g++",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.o",
                "`pkg-config",
                "opencv",
                "--libs",
                "--cflags",
                "opencv`"
            ],
            "options": {
                "cwd": "/usr/bin"
            },
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": []
        }
    ],
    "version": "2.0.0"
}
```

之后通过快捷键 command + shift + B 即可快速生成产物。
然后通过 ./test.o 执行生产的产物。

参考：
https://segmentfault.com/a/1190000019604411
https://www.jianshu.com/p/a36d41241ae8
