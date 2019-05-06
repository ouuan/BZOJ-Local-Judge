# BZOJ Local Judge

BZOJ Local Judge 计划为 OIer 提供一个完整、便捷的 BZOJ 离线题库使用平台，目前正处于开（gu）发（gu）阶段。

大约只会支持 Windows，只会支持 C++ 评测...

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

都请保存在 `./problems/problemid` 里，std 叫 `std.cpp`，generator 叫 `generator.cpp`（使用标准输入输出），题解形式随意，推荐使用 `tutorial.md`，也可以放网页的快捷方式（如果保存为 HTML 不影响观感推荐保存为 HTML）。

### 通过 issue 指出 bug / 提建议

建议的话，只要能为做题带来哪怕一丁点的方便，都可以提出来。

## 参考 / 使用的一些项目

[Ruanxingzhi / bzojch](https://github.com/Ruanxingzhi/bzojch)（[应该是允许他人使用的](https://github.com/Ruanxingzhi/bzojch/issues/2)）

[Sojiv / Project_lemon](https://github.com/Sojiv/Project_lemon)（评测部分借鉴了一下，复制了几句代码。原代码是基于 GPL-3.0 开源协议的。）

[MikeMirzayanov / testlib](https://github.com/MikeMirzayanov/testlib)（把 `testlib.h` 放进来了，用于编译 checker）