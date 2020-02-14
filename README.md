# BZOJ Local Judge

BZOJ Local Judge 计划为 OIer 提供一个完整、便捷的 BZOJ 离线题库使用平台，目前正处于弃坑阶段。（ouuan 已经开始主用 Linux，并且比起写一个 Linux 版，他更愿意给 [CP Editor](https://github.com/coder3101/cp-editor) 写类似的功能。）

大约只会支持 Windows...

## 开发理念

**追求极致的便捷。**

如果你需要一个稳定通用的比赛评测姬，可以使用 Lemon。

如果你需要一个既简洁又通用的评测姬，可以使用 icey。

如果你需要一个便捷的 OJ 刷题平台，使用本项目就对了。

## Getting Started

1. 输入命令 `git clone https://github.com/ouuan/BZOJLocalJudge.git`
2. 运行 `compileAll.bat`
3. 修改 `config.ini`
4. 输入命令 `opencpp 1000`
5. coding...
6. 输入命令 `judge 1000`
7. 获得评测结果！

详细使用说明及更多功能，请阅读[使用说明](GUIDEBOOK.md)。

## 贡献本项目

### 通过 pull request 补充 std / chekcer / generator / 题解

都请保存在 `./problems/problemid` 里，std 叫 `std.cpp`，generator 叫 `gen.cpp`（使用标准输入输出），题解形式随意，推荐使用 `tutorial.md`，也可以放网页的快捷方式（如果保存为 HTML 不影响观感推荐保存为 HTML）。

~~这一项可能要永久咕咕。~~

### 通过 issue 指出 bug / 提建议

建议的话，只要能为做题带来哪怕一丁点的方便，都可以提出来。

## F & Q

Q：`config.ini` 中的 `<path>` 之类的是什么，要手动替换吗？

A：会自动替换的，留着就好。

Q：为什么我运行时显示一堆”不是内部或外部命令，也不是可运行的程序“？

A：先检查你有没有编译主目录下的代码（或者运行 `compileAll.bat`）。如果已经编译了，要么是你没有修改 `config.ini`（比如，没装 IDM，应该修改下载命令），要么是你没有设置相应的环境变量。没设置环境变量的解决方法有两种，一种是把 g++、IDM、WinRAR 等程序所在路径加入环境变量 Path 中，另一种是在 `config.ini` 中把程序名替换为完整路径，如果路径带空格需要两端加引号并在前面加上 `call`。例如：`unZIPCommand call "C:\Program Files\WinRAR" x "<path>\<id>.zip" "<path>\"`。

Q：为什么主目录下的代码（用 `compileAll.bat` 编译的那些）我手动编译报错？

A：需要 C++11 才能正常编译，其中 `judger` 需要在编译选项中加入 `-lpsapi`。

Q：你这个东西并不便捷啊。

A：您好，只要花上不到五分钟配置一下，再熟悉一下命令，应该就足够方便了。尤其是没网的时候，比其它本地测评软件应该方便得多。如果真的遇到了什么问题，或者是有什么建议，欢迎在 [Issues](https://github.com/ouuan/BZOJLocalJudge/issues) 中提出。

## 应用于其它 OJ ？

把 BZOJ 题面删掉（或者放着不管），然后改一下 `config.ini`，就可以用于其它 OJ 了。

Example：（[LOJ](https://loj.ac/)）

```
unZIPCommand WinRAR x "<path>\<id>.zip" "<path>\<id>\"
downloadCommand IDMan /n /d https://loj.ac/problem/<id>/testdata/download /p <path> /f <id>.zip
```

## 参考 / 使用的一些项目

[Ruanxingzhi / bzojch](https://github.com/Ruanxingzhi/bzojch)（[应该是允许他人使用的](https://github.com/Ruanxingzhi/bzojch/issues/2)）

[Sojiv / Project_lemon](https://github.com/Sojiv/Project_lemon)（评测部分借鉴了一下，复制了几句代码。原代码是基于 GPL-3.0 开源协议的。）

[MikeMirzayanov / testlib](https://github.com/MikeMirzayanov/testlib)（把 `testlib.h` 放进来了，用于编译 checker）
