# 游戏指南

复制了[fandom](https://tetris.fandom.com/wiki/Tetris_Guideline)的文字。

- 游戏区域为 10×40，其中 20 行以上的行被隐藏或被场地框架阻挡，以误导玩家认为它是 10×20。在 2002 年指南中，高度至少为 22 行。
  - 如果硬件允许，第 21 行的几个像素将可见。
- 七巧板的颜色如下。
  - 青色 I
  - 黄色 O
  - 紫色或品红色 T
  - 绿色 S
  - 红色 Z
  - 蓝色 J
  - 橙色 L
- Tetriminos 的初始生成位置
    - I 和 O 生成在中间的列中
    - 其余方块生成在左侧中间列
    - 方块水平生成，J、L 和 T 会先以平放面生成
    - 在游戏区域上方生成，I 型方块生成在 21 行，其他方块生成在 21/22 行
    - 如果其路径上没有现有方块，立即下落一格
- 初始旋转和移动
    - 超级旋转系统/标准旋转系统（SRS）规定了四格方块旋转。
- 主机和掌机游戏手柄的标准映射：
    - 方向键的上下左右分别执行锁定硬降、非锁定软降（除部分游戏中第一帧的锁定）、左移位键和右移位键。
    - A（或其等效物）逆时针旋转 90 度，而 B（或其等效物）顺时针旋转 90 度。
    - 肩部按钮和 X（或其等效物）使用保持功能。
- 标准键盘映射：
    - 上箭头和 X 用于顺时针旋转 90°。
    - 空格键进行硬降。
    - Shift 键和 C 键用于锁定。
    - Ctrl 键和 Z 键用于逆时针旋转 90°。
    - Esc 键和 F1 键用于暂停。
    - 左、右和下箭头键与控制台上的相同。
    - 数字键盘控制：
        - 0 键用于保持。
        - 8、4、6 和 2 键分别对应硬降、左移位、右移位和软降。
        - 1、5 和 9 要顺时针旋转 90°。
        - 3 和 7 要逆时针旋转 90°。
- 手机的标准映射：
    - Arrow keys are the same as on the console.  
        方向键与主机上的相同。
        - If the cellphone does not have an OK button on the directional pad, the up arrow is to rotate clockwise.  
            如果手机的方向键上没有确认按钮，上箭头用于顺时针旋转。
    - OK to rotate clockwise.  
        确认顺时针旋转。
    - 2, 4, 6, and 8 are the same as up, down, left, and right respectively. (2 will always hard drop.)  
        2、4、6 和 8 分别对应上、下、左和右。（2 始终用于硬降。）
    - 0 is to hold.  
        0 用于保持。
    - 3, 5, 7, and # rotate clockwise.  
        3、5、7 和#顺时针旋转。
    - 1, 9, and * rotate counterclockwise.  
        1、9 和*逆时针旋转。
    - The left soft key is to pause.  
        左软键用于暂停。
        - If the cellphone does not have softkeys, the menu button (if separate from the OK button) is to pause.  
            如果手机没有软键，菜单按钮（如果与确定按钮分开）用于暂停。

- 所谓的 7-bag 随机生成器（也称为"随机包"或"7 系统"）
- "保留积木": 玩家可以按下一个按钮，将正在下落的四格方块送入保留格，同时之前在保留格中的四格方块会移动到屏幕顶部并开始下落。在积木锁定之前，不能再次使用保留功能。在少于八个可用按钮的平台（如 iPod 版本）上的游戏可能会跳过这个功能。保留积木和随机生成器的组合似乎可以让玩家无限游戏。这必须默认开启。
- 默认必须开启音效，包括旋转、移动、落在表面、触碰墙壁、锁定、行消除和游戏结束。
- 游戏必须默认开启幽灵方块功能。
- "帮助"部分使用的术语：
    - "Tetriminos"（首字母必须大写），而不是"tetrominoes"、"tetrads"或"pieces"。
    - 字母名称，而不是"square"、"stick"等。
- 指定的软降速度。不同指南版本的具体细节有所不同。
- 玩家只能通过消除行或执行 T-Spin 来升级。所需的行数取决于游戏。
    - 可以使用固定目标或可变目标。
    - 固定目标是 10 行
    - 可变目标是关卡数的 5 倍。
    - 可变目标关卡的行值如下：
        - 单行 = 1 行
        - 双倍 = 3 行
        - 三倍 = 5 行
        - 俄罗斯方块 = 8 行
- 游戏必须使用罗杰·迪恩的俄罗斯方块标志的一个变体，尽管这在 2000 年左右——在指南出现之前就是如此。
    - 标志的 T 形方块不应被分成 4 个小方块。
    - 标志不应被倾斜或扭曲。
    - The logo must be 2D.
- Game must include a song called [_Korobeiniki_](https://en.wikipedia.org/wiki/Korobeiniki "wikipedia:Korobeiniki"). This must be the default song.
- Uses half second [lock delay](https://tetris.fandom.com/wiki/Lock_delay "Lock delay").
- The player [tops out](https://tetris.fandom.com/wiki/Top_out "Top out") when a piece is spawned overlapping at least one block (block out), or a piece locks completely above the visible portion of the playfield (lock out).
- Must have 1 to 6 [next](https://tetris.fandom.com/wiki/Next "Next") pieces.
    - 6 is the recommended number of next pieces.
- Recognition and rewarding of [T-spin](https://tetris.fandom.com/wiki/T-Spin "T-Spin") moves. Conditions vary between guideline versions.
    - 2005 / 2009: 3-corner T
    - 2006: 3-corner T no kick
- Multiplayer and Arcade variations must have 15 moves/rotations before lock.
- Mini T-spin is when one of the minoes next to pointing side is empty, or holes were made without using the triple kick.
- Rewarding of Back to Back chains. (Tetris / T-spin)Recognition method depends on the game.
- Marathon mode must have 15 levels.
- 40 line mode (called sprint or 40 lines)
- 2 or 3 minute timed mode (called ultra)
- Speed curve must be the same as [Tetris Worlds.](https://tetris.fandom.com/wiki/Tetris_Worlds "Tetris Worlds")
- Game must use a scoring system described [here.](https://tetris.fandom.com/wiki/Scoring#Guideline_scoring_system "Scoring")
- Game must count down from 3 after you press start, and after you resume a paused game.
- Game must have this notice when the game starts (XXXX is the year the game was created):
