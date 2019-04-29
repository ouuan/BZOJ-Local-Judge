# BZOJ Local Judge

BZOJ Local Judge 计划为 OIer 提供一个完整、便捷的 BZOJ 离线题库使用平台，目前正处于开（gu）发（gu）阶段。

大约只会支持 Windows，只会支持 C++ 评测...

## 使用说明（有的功能还没实现）

### 准备

1. `git clone https://github.com/ouuan/BZOJLocalJudge.git`
2. [下载 BZOJ 数据](http://darkbzoj.tk/blogof/root/blog/10)（也可以需要时再自动下载）
3. 编译根目录下所有 cpp 文件（可以使用 `compileAll.bat`）（若 `judger.cpp` 编译失败请尝试在编译命令中加上 `-lpsapi`）
4. 在 `config.txt` 中进行设置。

### 文件路径

1. 各项设置位于根目录下的 `config.json` 里。
2. 数据存放在 `./data/problemid(.zip)` 里，文件夹内为 `testid.in` / `testid.out`，压缩包内为名为 `problemid` 的文件夹。
3. 题面存放在 `./problems/problemid/problemid.html` 里。
4. 源码、std、generator、checker、题解都放在 `./problems/problemid` 里，文件名分别为 `problemid.cpp`, `std.cpp`, `generator.cpp`, `checker.cpp`, `tutorial.*`。
5. 评测、对拍时的输出也放在 `./problems/problemid` 里，分别叫 `problemid-testid.out` 和 `problemid.out`。

### 使用方法

#### 设置

为了使用方便没有使用 Python..于是没有用 json 来作为设置，而是直接用了 txt。格式大约是每行一个设置，**请不要修改每行的第一个单词或顺序，不要添加空行**。

`defaultTimeLimit`：默认时限，以 `ms` 为单位。

`defaultMemoryLimit`：默认空间限制，以 `MiB` 为单位。

`compileCommand`：编译命令，提供 `<path>` 表示源代码路径（不含 `.cpp`）。输出文件应为 `<path>.exe`。

`unZIPCommand `：解压命令，提供 `<ZIPpath>` 表示 zip 路径（包含 `.zip`），`<unZIPpath>` 表示解压路径。

`downloadCommand `： 用于自动下载数据，提供 `<link>` 表示下载地址，`<path>` 表示保存路径（不含文件名），`<name>` 表示保存文件名。

`username/password`：自动提交使用。

#### 打开 cpp

`opencpp <problemid>`：打开 `./problems/problemid/problemid.cpp`。若不存在则将 `./template.cpp` 拷贝到 `./problems/problemid/problemid.cpp` 并打开。

#### 打开题面

`statement <problemid>`：打开 `./problems/problemid/problemid.html`。

#### 打开文件夹

`opendir <problemid> [type = 1]`：`type = 1` 时打开 `./problems/problemid`，`type = 2` 时打开 `./data/problemid`。打开数据时若数据不存在会自动下载 / 解压。

#### 查看近期做题

`view [number]`：显示修改时间最晚的 `number` 道题，若留空则显示所有近期做了的题（按修改时间降序）。

#### 评测

使用 `./problems/problemid/problemid.cpp` 作为源文件、使用 `./data/problemid(.zip)` 里的数据进行评测： `judge <problemid> [timeLimit [memoryLimit [checkerPath]]]`。（需要 SPJ 时填第四个参数，若为 `1` 表示用 `./problems/problemid/checker.cpp`，否则使用所填路径作为 checker；需要与 `config.json` 中不同的时限、空间限制填第二、三个参数；评测时优先使用 `data` 内已解压数据，其次使用未解压数据，仍没有则尝试自动下载数据。）

打开某个测试点数据及评测输出：`opentest <problemid> <testid>`。

使用指定的源程序和输入输出答案文件进行评测：`judger <executableFile> <inputFile> <outputFile> <answerFile> <timeLimit> <memoryLimit> [checkerPath]`。

#### 对拍

`dp <problemid> [generateCommand [checkerPath]]`：若 `generateCommand` 留空则使用 `./problems/problemid/generator.cpp` 生成数据（`generator.cpp` 应使用标准输入输出），否则使用 `generateCommand` 生成数据（`generateCommand` 应在 `./problems/problemid/dp.in` 生成数据），将 `problemid.cpp` 和 `std.cpp` 进行对拍，若 `checkerPath` 留空则使用 `fc` 来检查，否则使用 `checker`，若 `checkerPath` 为 `1` 则使用 `./problems/problemid/checker.cpp` 作为 `checker`。

#### 在 OJ 中打开题目

`openbzoj <problemid>`：打开题目的 [BZOJ](https://www.lydsy.com/JudgeOnline/) 页面。

`opendarkbz <problemid>`：打开题目的 [darkBZOJ](https://darkbzoj.tk/) 页面。

#### 在 OJ 上批量提交

需要安装 Python & selenium 库，需要一个 Google Chrome 浏览器，需要 [下载 chromedriver](http://npm.taobao.org/mirrors/chromedriver/) 并放在 Chrome 安装目录的 `Application` 文件夹内，需要在 `config.txt` 中填写用户名和密码。

`python submitbzoj.py [date]`：在 BZOJ 上自动提交 `problems` 文件夹下所有（修改日期自 `date` 起）和题目 id 同名的代码。`date` 格式为 `yyyy-mm-dd`。

`python submitdarkbz.py [date]`：同上，在 darkBZOJ 上。

## 参与贡献

项目代码应该都是我写..然而 std、generator、题解需要大家的贡献来完善。

1. fork 本项目。
2. 把 fork clone 到本地 / 直接在网页端修改。
3. 提交 pull request。

都请保存在 `./problems/problemid` 里，std 叫 `std.cpp`，generator 叫 `generator.cpp`（使用标准输入输出），题解形式随意，推荐使用 `tutorial.md`，也可以放网页的快捷方式（如果保存为 HTML 不影响观感推荐保存为 HTML）。

## 使用项目

[Ruanxingzhi / bzojch](https://github.com/Ruanxingzhi/bzojch)（[应该是允许他人使用的](https://github.com/Ruanxingzhi/bzojch/issues/2)）

[Sojiv / Project_lemon](https://github.com/Sojiv/Project_lemon)（评测部分借鉴了一下，复制了几句代码。原代码是基于 GPL-3.0 开源协议的。）