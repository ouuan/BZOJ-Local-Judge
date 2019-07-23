## 使用说明

### 准备

1. `git clone https://github.com/ouuan/BZOJLocalJudge.git`
2. [下载 BZOJ 数据](http://wwwwodddd.com/lydsy/)（也可以需要时再自动下载）
3. 编译根目录下所有 cpp 文件（可以使用 `compileAll.bat`）（若 `judger.cpp` 编译失败请尝试在编译命令中加上 `-lpsapi`）
4. 在 `config.ini` 中进行设置。
5. 确保 `.in` 和 `.out` 设置了默认打开方式。

### 文件路径

1. 各项设置位于根目录下的 `config.ini` 里。
2. 数据存放在 `./data/problemid(.zip)` 里，文件夹内为 `testid.in` / `testid.out`，压缩包内为名为 `problemid` 的文件夹。
3. 题面存放在 `./problems/problemid/problemid.html` 里。
4. 源码、std、generator、checker、题解都放在 `./problems/problemid` 里，文件名分别为 `problemid.cpp`, `std.cpp`, `gen.cpp`, `checker.cpp`, `tutorial.*`。
5. 评测、对拍时的输出也放在 `./problems/problemid` 里，分别叫 `problemid-testid.out` 和 `problemid.out`。

### 使用方法

#### 设置

为了使用方便没有使用 Python..于是没有用 json 来作为设置，而是直接用了 txt。格式大约是每行一个设置，**请不要修改每行的第一个单词或顺序，不要添加空行**。

`defaultTimeLimit`：默认时限，以 `ms` 为单位。

`defaultMemoryLimit`：默认空间限制，以 `MiB` 为单位。

`compileCommand`：编译命令，提供 `<path>` 表示源代码路径（不含 `.cpp`，不带引号，为了防止路径中含空格需要在 `<path>` 两端加上引号）。输出文件（`-o`）应为 `<path>.exe`。

`unZIPCommand `：解压命令，提供 `<path>` 表示 `data` 文件夹路径（不带引号，绝对路径），`<id>` 表示题目编号。注意设置环境变量，确保自己在 cmd 中可以使用填入的命令下载。

`downloadCommand `： 用于自动下载数据，提供 `<id>` 表示题目 id，`<path>` 表示保存路径（不含保存的文件名 ，带引号）。注意设置环境变量，确保自己在 cmd 中可以使用填入的命令解压。

`templatePath`：使用 `opencpp` 命令时会使用这个文件作为模板。路径无需加引号。

#### 打开 cpp

`opencpp <problemid>`：打开 `./problems/problemid/problemid.cpp`。若不存在则将 `./template.cpp` 拷贝到 `./problems/problemid/problemid.cpp` 并打开。

#### 打开题面

`openstatement <problemid>`：打开 `./problems/problemid/problemid.html`。

#### 打开文件夹

`opendir <problemid>`：打开 `./problems/problemid`。
`opendata <problemid>`：打开 `./data/problemid`。若数据不存在会自动下载 & 解压。

#### 评测

使用 `./problems/problemid/problemid.cpp` 作为源文件、使用 `./data/problemid(.zip)` 里的数据进行评测： `judge <problemid> [timeLimit [memoryLimit [checkerPath]]]`。（需要与 `config.ini` 中不同的时限、空间限制填第二、三个参数；需要 SPJ 时填第四个参数，若为 `1` 表示用 `./problems/problemid/checker.cpp` 作为 checker 且自动编译，否则使用所填 **exe** 作为 checker；评测时优先使用 `data` 内已解压数据，其次使用未解压数据，仍没有则尝试自动下载数据。）结果保存在 `./problems/problemid/judge.out` 中，并在评测完成时自动打开。

打开某个测试点数据及评测输出：`opentest <problemid> <testid>`。

打开某道题未 AC 的测试点中输入文件最小的：`openmin <problemid>`。

使用指定的源程序和输入输出答案文件进行评测：`judger <executableFile> <inputFile> <outputFile> <answerFile> <timeLimit> <memoryLimit> [checkerPath]`。结果在 `judger.out` 中。评测时，出现以下情况将会强制终止程序：1. 使用内存超过限制的 2 倍；2. realTime 超过时限的 2 倍；3. 评测姬运行时间超过时限的 4 倍。这里解释一下，realTime 能够比较准确地描述程序用时，但有时会出现程序运行时间远大于 realTime 的情况，会造成评测卡壳的现象，因此同时会用 `clock()` 函数获取评测姬运行时间，超过时限 4 倍则强制终止程序。（之前我在广二集训的时候好像听人吐槽过用时小于时限 TLE，就是这样解释的。）

#### 对拍

`dp <problemid> [generateCommand [checkerPath]]`：若 `generateCommand` 留空则使用 `./problems/problemid/gen.cpp` 生成数据（`gen.cpp` 应使用标准输入输出），否则使用 `generateCommand` 生成数据（`generateCommand` 应在 `./problems/problemid/dp.in` 生成数据），将 `problemid.cpp` 和 `std.cpp` 进行对拍，若 `checkerPath` 留空则使用 `fc` 来检查，否则使用 `checker`，若 `checkerPath` 为 `1` 则使用 `./problems/problemid/checker.cpp` 作为 `checker`。

#### 在 OJ 中打开题目

`openbzoj <problemid>`：打开题目的 [BZOJ](https://www.lydsy.com/JudgeOnline/) 页面。

`opendarkbz <problemid>`：打开题目的 [darkBZOJ](https://darkbzoj.tk/) 页面。
