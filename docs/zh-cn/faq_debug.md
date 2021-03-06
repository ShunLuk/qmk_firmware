# 调试的常见问题

本篇详细介绍了人们在键盘故障排除时的各种常见问题。

# 调试控制台

## `hid_listen` 无法识别设备
当设备的调试控制台未就绪时，您将看到如下内容：

```
Waiting for device:.........
```

插入设备后，*hid_listen*找到该设备，您将收到以下消息：

```
Waiting for new device:.........................
Listening:
```

如果您无法获得这条“Listening:”消息，请尝试在[Makefile]中使用 `CONSOLE_ENABLE=yes`

在Linux这样的操作系统上，你可能需要一些权限。
- 使用`sudo hid_listen`

## 控制台没有返回消息
检查:
- *hid_listen* 找到了你的设备。看前面。
- 输入**Magic**+d打开调试。详见[Magic Commands](https://github.com/tmk/tmk_keyboard#magic-commands)。
- 设置`debug_enable=true` ，一般存在于**matrix.c**的`matrix_init()`中。
- 尝试使用'print'函数而不要用调试输出。详见**common/print.h**。
- 断开其他有控制台功能的设备。 详见[Issue #97](https://github.com/tmk/tmk_keyboard/issues/97)。

## Linux或UNIX这样的系统如何请求超级用户权限
用'sudo'来执行*hid_listen*就有权限了。
```
$ sudo hid_listen
```

或者把一个文件放到规则文件夹来为TMK设备添加*udev规则*，不同系统的目录可能有所不同。

文件: /etc/udev/rules.d/52-tmk-keyboard.rules(在Ubuntu系统的情况下)
```
# tmk keyboard products     https://github.com/tmk/tmk_keyboard
SUBSYSTEMS=="usb", ATTRS{idVendor}=="feed", MODE:="0666"
```

***

# 其他
## 安全注意事项

你应该不想要把你的键盘变成"砖头"吧，就是变成没法重写固件的那种。
下面讲解一些参数来告诉你什么风险很大（其实也不是很大）。

- 假如你键盘表面没有设计重置键"RESET", 那你要进入bootloader的话就要按PCB上的RESET了。
  按PCB上的RESET要拧开键盘底部。
- 如果 tmk_core / common 里面的文件丢失键盘可能失灵。
- .hex太大可能不太好; `make dfu` 会删除块，检验大小（咦?好像反了...）。
  一但出错，刷新键盘失败的话就困在DFU出不去了。
  - 所以, 要知道大小限制。 Planck键盘上.hex文件最大大小是 is 7000h (十进制是28672)

```
Linking: .build/planck_rev4_cbbrowne.elf                                                            [OK]
Creating load file for Flash: .build/planck_rev4_cbbrowne.hex                                       [OK]

Size after:
   text    data     bss     dec     hex filename
      0   22396       0   22396    577c planck_rev4_cbbrowne.hex
```

  - 上面那个文件大小是 22396/577ch，比28672/7000h小
  - 当你有一个合适的.hex文件时，你就要重试加载那个了
  - 您在键盘Makefile中的某些选项可能消耗额外内存；注意以下这几个
    BOOTMAGIC_ENABLE, MOUSEKEY_ENABLE, EXTRAKEY_ENABLE, CONSOLE_ENABLE, API_SYSEX_ENABLE
- DFU 工具/不/可以写入bootloader (unless you throw in extra fruit salad of options), 
  所以还是有点危险的
- EEPROM大概有100000次循环寿命。不要总是频繁重写固件；EEPROM会玩坏的。
## 全键无冲不好用
首先你要在**Makefile**用如下命令编译固件`NKRO_ENABLE`。

全键无冲还不好用的话试着用`Magic` **N** 命令(默认是`LShift+RShift+N`)。这个命令会在**全键无冲**和**六键无冲**之间临时切换。有些情况**全键无冲**不好用你就需要使用**六键无冲**模式，尤其是在BIOS中。


## 指点杆需要复位电路(PS/2 鼠标支持)
如果没有复位电路，由于硬件初始化不正确，您将得到不一致的结果。查看TPM754复位电路。

- https://geekhack.org/index.php?topic=50176.msg1127447#msg1127447
- https://www.mikrocontroller.net/attachment/52583/tpm754.pdf


## 矩阵不可读16以上的列
当列超过16时[matrix.h]的`read_cols()`中，用`1UL<<16`而不要用`1<<16`。

在C语言中`1` 是一个[int] 类型的[16 bit]值，在AVR中你不能左移大于15次。如果你使用`1<<16`的话会得到意外的零。你要用 [unsigned long]类型，比如`1UL`。

https://deskthority.net/workshop-f7/rebuilding-and-redesigning-a-classic-thinkpad-keyboard-t6181-60.html#p146279

## 特殊额外键不起作用(系统，音频控制键)
你要在`rules.mk`定义`EXTRAKEY_ENABLE`在QMK中使用它们。

```
EXTRAKEY_ENABLE = yes          # 音频控制和系统控制
```

## 睡眠唤醒不好用

在Windows查看设备管理器中该键盘设备属性中电源管理选项卡中的`允许此设备唤醒计算机(O)`是否勾选。同时看一眼BIOS设置。

在主机睡眠时按下任何键都可以唤醒了。

## 使用Arduino?

**注意Arduino的针脚名字和主控芯片的不一样。** 比如, Arduino的`D0`并不是`PD0`。自己用原理图捋一下电路。

- https://arduino.cc/en/uploads/Main/arduino-leonardo-schematic_3b.pdf
- https://arduino.cc/en/uploads/Main/arduino-micro-schematic.pdf

Arduino Leonardo和micro使用**ATMega32U4**，该芯片TMK可用，但Arduino的bootloader会导致问题。

## USB 3 兼容性
据传说有些人用USB3接口会有问题，用USB2的试试。


## Mac 兼容性
### OS X 10.11 和集线器
https://geekhack.org/index.php?topic=14290.msg1884034#msg1884034


## 对于BIOS (UEFI)/恢复(睡眠和唤醒)/重新启动 有问题
有人说他们的键盘在BIOS中，或许是恢复(睡眠和唤醒)后不工作.

截止至目前，其根本原因未知，不排除与某些构建选项有关。试着在Makefile中失能`CONSOLE_ENABLE`, `NKRO_ENABLE`, `SLEEP_LED_ENABLE`这样的选项，也试试其他的。

https://github.com/tmk/tmk_keyboard/issues/266
https://geekhack.org/index.php?topic=41989.msg1967778#msg1967778
