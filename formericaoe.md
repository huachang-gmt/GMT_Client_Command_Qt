我查閱了你提供的傳承光電（Formerica Optoelectronics）官方網站，也進一步比對了 GMT 的設備資料。

目前找到一個**非常吻合主管所說的「Dual Lens」和「Auto Load」的設備**。而且有一個很重要的發現：GMT 公開的這台設備，規格中明確寫著使用 **LabVIEW** 作為程式開發語言。

我先說結論：

**你接下來很可能要接觸的是 GMT 的 Dual LD Lens Active Aligner（雙 LD Lens 主動對位設備），而不是之前我們討論的普通六軸電動滑台控制專案。**

不過，目前還不能百分之百確認這就是交付給傳承光電的那一台實機。

# 一、先了解傳承光電是什麼公司



Formerica Optoelectronics（傳承光電）主要從事光通訊產品的製造。

從它的官方網站可以看到主要產品包括：

- Optical Transceiver（光收發模組）
- Active Optical Cable（主動式光纜）
- Optical Bypass Module（光旁路模組）
- 800G、400G、200G 等高速光通訊產品。

官方網站目前特別強調 AI Data Center、800G 及 1.6T 光通訊應用。[formericaoe.com](https://www.formericaoe.com/)

官方網站：[Formerica 傳承光電](https://www.formericaoe.com/?utm_source=chatgpt.com)

這代表我們可以先建立一個背景：

傳承光電的產品與光收發模組有關，因此設備可能涉及光學元件的組裝、耦光、定位及檢測。

但這只是產業背景，還不能單憑公司產品就確定實際設備用途。

# 二、找到高度吻合的設備：GMT Dual LD Lens Active Aligner

我在 GMT 官方網站找到這個產品：

Dual LD Lens Active Aligner

[GMT Dual LD Lens Active Aligner 官方產品頁](https://www.gmt.tw/en/gmt-high-precision-coupling-solutions-for-silicon-photonics?utm_source=chatgpt.com)

它的名稱與主管提到的 Dual Lens 非常吻合。

官方列出的主要功能：

1. Dual Lens Coupling：雙透鏡耦合。
2. Lens Align with PIC：透鏡與 PIC 對位。
3. 使用 UV Glue 固定透鏡。
4. UV Curing：紫外線固化。
5. TX Power：監測發射端光功率。
6. 同時進行兩個 Lens 的耦合。[gmt.tw](https://www.gmt.tw/en/gmt-high-precision-coupling-solutions-for-silicon-photonics)

### 這台設備實際在做什麼？

先介紹幾個名詞：

| 名詞 | 意思 |
|---|---|
| Lens | 透鏡 |
| Dual Lens | 兩個透鏡 |
| PIC | Photonic Integrated Circuit，光子積體電路 |
| Coupling | 光學耦合，讓光能有效進入目標光學結構 |
| Active Alignment | 主動對位，透過實際光學訊號回饋尋找最佳位置 |
| UV Curing | 使用紫外線讓膠水固化 |

簡單說明它的工作：

假設我們要把兩個透鏡精確安裝在 PIC 上。

```text
       Lens 1                 Lens 2
          │                      │
          ▼                      ▼
     ┌────────┐             ┌────────┐
     │ 透鏡 1  │             │ 透鏡 2  │
     └────────┘             └────────┘
          │                      │
          └──────────┬───────────┘
                     ▼
              ┌────────────┐
              │    PIC     │
              │ 光子積體電路 │
              └────────────┘
```

設備需要調整透鏡的位置，使光學訊號達到要求。

它不只是把透鏡放到指定位置，而是需要透過光功率等訊號，尋找適當的耦合位置。

找到位置後，再使用 UV 膠固定。

這就是 Active Alignment 的核心概念。

官方產品頁也列出 X/Y/Z 高精度對位，以及兩個 Lens 同時耦合。[gmt.tw](https://www.gmt.tw/en/gmt-high-precision-coupling-solutions-for-silicon-photonics)

# 三、主管提到的 Auto Load，對應到哪裡？

這是我找到的另一個重要線索。

GMT 這台設備的規格表有一個項目：

**Loading / Unloading Module（上下料模組）**

官方列出的內容：

| 項目 | 官方規格 |
|---|---|
| Lens loading tray | 32pc dual lens tray |
| PCB | Single PCB tray with Pneumatic clamping |

也就是說：

- Lens 使用專用 Tray 放置。
- 一個 Tray 可以放置 32 組雙 Lens。
- PCB 使用另一個 Tray。
- PCB 透過氣動夾持固定。

這與主管說的 Auto Load 非常吻合。[gmt.tw](https://www.gmt.tw/en/gmt-high-precision-coupling-solutions-for-silicon-photonics)

不過要注意：官方公開的是上下料模組及 Tray 規格，實際的自動取料、搬運、定位及下料順序，仍需要實機或機台操作文件確認。

# 四、最重要的發現：這台設備使用 LabVIEW！

這一點我認為特別值得注意。

GMT 官方產品規格明確列出：

**Software → Programming language → LabVIEW**

而且還列出：

| 項目 | 規格 |
|---|---|
| Programming language | LabVIEW |
| Camera | 2 台 |
| Visual recognition | 5 Megapixel CCD |
| Camera axis | XYZ 三軸步進馬達搭配滾珠螺桿 |
| Alignment Module | Dual 6-axis System |
| Loading/Unloading | Lens Tray、PCB Tray |
| Dispensing | Dual Dispensers |
| UV Curing | 365nm LED |
| Data Storage | 可保存生產資料 |
| Program Calls | 可儲存多種對位程式 |

以上都是 GMT 官方公開的規格。[gmt.tw](https://www.gmt.tw/en/gmt-high-precision-coupling-solutions-for-silicon-photonics)

這些資訊與你主管交代的 IPC + LabVIEW 工作方向相當接近。

尤其是：

- 使用 IPC 執行 LabVIEW。
- 控制機台運動。
- Camera 視覺辨識。
- 自動上下料。
- 雙 Lens 主動對位。
- 生產資料記錄。

這可能就是你接下來要接手的設備軟體工作。

---

# 五、我幫你整理一下目前的判斷

| 主管提到的名詞 | GMT 官方產品資料 | 符合程度 |
|---|---|---|
| 傳承光電 | Formerica 光通訊產品應用背景 | 符合客戶背景 |
| Dual Lens | Dual LD Lens Active Aligner | 高度吻合 |
| Auto Load | Loading/Unloading Module | 高度吻合 |
| LabVIEW | 官方規格明確列出 LabVIEW | 高度吻合 |
| IPC 控制機台 | 官方列出 LabVIEW 軟體，但未公開 IPC 型號及控制架構 | 尚待確認 |

我的判斷是：**這台 GMT Dual LD Lens Active Aligner 是目前最值得優先研究的候選設備。**

但目前公開資料沒有證明這台設備就是專門交付給 Formerica 的訂單，因此我不會把這件事當成已確認事實。

# 六、這會改變我們接下來的學習方向

我認為這次工作變化很重要。

之前我們的重心是：

STM32H755 → EtherCAT Master → Servo Drive → 六軸滑台。

現在應該改成：

```text
              IPC
               │
               ▼
           LabVIEW
               │
       ┌───────┼────────┐
       ▼       ▼        ▼
    Motion   Camera   I/O Control
    Control  Vision   氣動/真空/感測器
       │       │        │
       ▼       ▼        ▼
    電動軸    影像辨識  Auto Load
       │
       ▼
    雙 Lens 對位
       │
       ▼
    光功率確認
       │
       ▼
    點膠與 UV 固化
       │
       ▼
    完成下料
```

這是依照公開功能整理的**概念架構**，不是已確認的實機接線圖或 LabVIEW 程式架構。

## 我建議接下來分成四個學習方向

| 優先順序 | 學習主題 | 你需要掌握的內容 |
|---|---|---|
| 1 | LabVIEW 基礎與機台控制 | VI、Block Diagram、Front Panel、DAQ、通訊、狀態機 |
| 2 | GMT Dual Lens 設備機構 | 六軸運動、上下料、夾爪、真空、點膠、UV |
| 3 | Machine Vision | Camera 取像、影像辨識、座標轉換、對位 |
| 4 | Active Alignment | 光功率回授、位置搜尋、最佳耦合、完成判斷 |

這次不應該再以 STM32 或 EtherCAT 為主線，除非之後確認這台 IPC 的底層運動控制確實使用 EtherCAT。

---

# 七、我想先確認一件最重要的事情

目前我們已經找到高度吻合的設備，但還需要確認主管交給你的工作範圍。

**你主管所說的「使用 IPC 上的 LabVIEW 控制機台」，比較接近以下哪一種情況？**

A. **從零開始開發 LabVIEW 程式**：目前沒有程式，需要你從頭建立機台控制軟體。

B. **接手既有 LabVIEW 專案**：同事或其他工程師已經寫好程式，你需要理解、修改及維護。

C. **既有程式需要增加功能**：例如增加 Auto Load、Dual Lens 對位或其他控制功能。

D. **目前還不清楚**：主管只交代工作方向，尚未提供程式及機台資料。

這個答案會決定我們下一步該先學 LabVIEW 基礎，還是先研究機台的工作流程及既有程式架構。

---

我認為你的方向是對的，而且我建議我們**先不要急著進入 LabVIEW 程式教學，應該先完整了解 GMT Dual LD Lens Active Aligner 的設備架構與製程流程**。

因為你接下來的工作是 B（接手既有程式）和 C（依客戶需求新增功能）。如果還不知道機台每個機構的用途、各軸如何運動、相機如何定位、光功率如何回授，就直接看 LabVIEW 程式，很容易只看懂程式碼，卻不明白它為什麼要這樣控制。

至於傳承光電為什麼需要這台設備、可能用在哪一種產品，我重新查看了官方網站，找到一些有用的線索。

# 一、先了解 GMT 設備，為什麼是合理的順序？

我們目前鎖定的候選設備是：

****

從 GMT 公開的規格來看，這台設備不是單純的自動點膠機，而是整合了精密定位、機器視覺、光功率量測、主動式光學對位、點膠與 UV 固化的設備。

我建議把它拆成六個部分學習：

| 順序 | 設備子系統 | 我們要了解的問題 |
|---|---|---|
| 1 | 機械結構 | 工件放在哪裡？Lens 如何固定？各個平台如何移動？ |
| 2 | Motion Control | X/Y/Z 與旋轉軸如何運動？由什麼控制器驅動？ |
| 3 | Machine Vision | Camera 如何找到 Lens、PIC 的位置與角度？ |
| 4 | Optical Measurement | 如何量測 TX Power？如何知道對位是否正確？ |
| 5 | Active Alignment | 如何移動 Lens，找出光功率最佳的位置？ |
| 6 | Auto Load / Unload | 如何自動取料、放料、夾持及搬運？ |

另外，還要了解 UV 點膠與固化，以及整台機台的安全互鎖。

## 二、這台設備的整體運作流程

先用簡化流程理解：

```text
       Auto Load
           │
           ▼
    放入待加工工件
           │
           ▼
     Camera 影像定位
           │
           ▼
    Lens / PIC 初步對位
           │
           ▼
     Active Alignment
           │
           ▼
    讀取 TX Optical Power
           │
           ▼
   微調位置，尋找最佳光功率
           │
           ▼
        點 UV Glue
           │
           ▼
       UV Curing
           │
           ▼
       檢查加工結果
           │
           ▼
        Auto Unload
```

這是依據 GMT 公開功能整理的**原理流程示意**，不是已經確認的實機程式順序。實際步驟、是否有其他檢查站，以及工件如何搬運，都要等取得設備文件後確認。

這裡有一個非常重要的觀念：

**Active Alignment 和一般 Camera Alignment 不完全相同。**

- Camera Alignment：透過影像找到物件的位置與角度。
- Active Alignment：實際監測光訊號，移動 Lens，尋找光耦合效果最好的位置。

也就是說，Camera 可以幫助設備找到初始位置，但最終的光學最佳位置，可能需要透過 TX Power 回授來決定。

這會是我們後續課程的重要核心。

---

# 三、傳承光電為什麼需要這台設備？

這部分我重新查閱了 [傳承光電官方網站](https://www.formericaoe.com/?utm_source=chatgpt.com)。

目前找到三個重要線索。

## 1. 傳承光電主要產品是光收發模組

傳承光電官方介紹表示，公司提供光通訊連接解決方案，產品包含：

- Optical Transceiver（光收發模組）
- Active Optical Cable（主動式光纜）
- Optical Bypass Module（光旁路模組）
- DAC（Direct Attach Cable）
- 其他光通訊連接產品

產品速率涵蓋 10G、25G、100G、200G、400G，並持續發展 800G 與 1.6T 等產品。[formericaoe.com](https://www.formericaoe.com/en/a1-10999/About-Us.html?utm_source=chatgpt.com)

## 2. 目前特別強調 800G、1.6T 光收發產品

我找到傳承光電官方的產品介紹：

[傳承光電 Optical Transceivers 產品分類](https://www.formericaoe.com/en/product-c29051/Optical-Transceivers.html?utm_source=chatgpt.com)

其中包括：

- 800G OSFP / QSFP-DD
- 400G QSFP-DD / QSFP112
- 200G QSFP56
- 100G QSFP28
- 其他光收發模組

官方也有一份 800G OSFP 2xDR4 產品規格文件，描述其具有雙 MPO-12 光纖接口，並用於 800Gb/s 光通訊。[formericaoe.com](https://www.formericaoe.com/files/TES-J18BF-CFC%20V1.0.pdf?utm_source=chatgpt.com)

這表示傳承光電確實有高速光收發模組產品線。

## 3. 為什麼會需要 Dual LD Lens Active Aligner？

這裡要先理解設備名稱：

**Dual LD Lens Active Aligner**

可以拆成：

| 名稱 | 意義 |
|---|---|
| Dual | 雙組、雙通道或雙工件相關設計 |
| LD | Laser Diode，雷射二極體 |
| Lens | 透鏡 |
| Active Aligner | 主動式光學對位設備 |

這台設備的主要任務，是將 Lens 與光學元件進行精密對位，並透過光功率量測尋找最佳耦合位置。

為什麼這件事重要？

光收發模組需要把電訊號轉換成光訊號，再透過光纖傳輸。

以發射端（TX）為例，可以先用以下簡化概念理解：

```text
電訊號
   │
   ▼
Laser Diode（LD）
   │
   ▼
光訊號
   │
   ▼
Lens（透鏡）
   │
   ▼
光纖 / 光學介面
   │
   ▼
傳輸出去
```

Lens 的位置、角度及光軸如果沒有正確對準，就可能造成光耦合效率下降。

因此，需要精密機構移動 Lens，並透過光功率回授尋找最佳位置。

這就是 Active Alignment 的價值。

---

# 四、那麼，它究竟是用在傳承光電的哪一個產品？

這是目前最值得繼續追查的問題。

我把目前的證據分成三個層次：

| 判斷項目 | 目前掌握的證據 | 判斷 |
|---|---|---|
| 傳承光電有光收發模組產品 | 官方產品頁 | 已確認 |
| GMT 有 Dual LD Lens Active Aligner | GMT 官方設備頁 | 已確認 |
| GMT 設備可能用於傳承光電的光收發模組製程 | 設備功能與產品類型相符 | 合理推測 |
| 確切用於 400G、800G 或 1.6T 哪一款產品 | 尚無公開資料證明 | 未確認 |

我特別提醒一件事：

**目前不能因為傳承光電有 800G 產品，就直接認定這台設備是用來生產 800G 模組。**

例如，官方公開的 800G 2xDR4 規格，只能證明傳承光電有這類產品，不能證明 GMT 的 Dual LD Lens Active Aligner 就是為這款產品設計。

另外，設備名稱中的 Dual LD Lens，也不能直接推論它一定對應某個特定封裝形式或產品型號。

我們需要取得客戶實際的製程資料才能確認。

---

# 五、我建議我們接下來的學習順序

我想把這件事當成一個完整的設備學習專案，而不是單純學習 LabVIEW 語法。

| 階段 | 學習內容 | 最後希望達成的能力 |
|---|---|---|
| 第一階段 | GMT Dual LD Lens Active Aligner 整體架構 | 看得懂整台設備 |
| 第二階段 | 機構、馬達、平台、氣動、真空 | 知道每個機構如何動作 |
| 第三階段 | Camera、Machine Vision | 理解視覺定位與座標轉換 |
| 第四階段 | LD、Lens、光功率、Active Alignment | 理解光學對位製程 |
| 第五階段 | Auto Load / Unload | 理解自動上下料 |
| 第六階段 | LabVIEW 程式架構 | 看懂既有程式如何控制設備 |
| 第七階段 | 實際專案程式 Trace | 從操作畫面追蹤到控制程式 |
| 第八階段 | 新功能開發 | 能夠修改、增加功能並驗證 |

LabVIEW 部分，我們會特別注意：

- Front Panel：操作人員看到的畫面。
- Block Diagram：實際控制邏輯。
- State Machine：設備運作狀態。
- SubVI：功能模組。
- Error Cluster：錯誤傳遞與處理。
- Motion / Vision / Power Meter：各種硬體控制介面。

最後才進入既有程式的唯讀盤點，確認實際使用的控制器、相機、馬達驅動器、光功率計與 I/O。

---

# 六、我想先確認一件關鍵事情

既然你未來會接手既有 LabVIEW 程式，而且可能需要依照傳承光電的需求增加功能，我認為還有一份資料比 LabVIEW 程式碼更值得優先取得：

**GMT 交付給客戶的設備操作手冊、設備架構圖（System Architecture）、電氣圖（Electrical Diagram）及製程流程圖（Process Flow）。**

這些資料能幫助我們確認真正的實機架構，而不是只根據官網規格猜測。

我想先問你：

**你目前是否已經取得 GMT Dual LD Lens Active Aligner 的任何文件，或者有機會向同事或主管索取？**

如果目前還沒有也沒關係，我們可以先依據 GMT 官方公開規格，從第一課開始，逐步建立完整的設備架構知識。

---

我同意你的推測，而且這會影響我們後續學習的方式。

我認為目前可以先建立一個工作假設：

**GMT 可能以現有的 Dual LD Lens Active Aligner 為基礎，依照傳承光電的產品需求、製程條件及自動化要求，進行客製化修改。**

這種情況在自動化設備開發中很常見。不過，目前還沒有客戶規格書或設備交付文件，所以我們先把它當作假設，而不是已確認的事實。

## 一、我們的學習目標

我希望最後你能做到以下幾件事：

1. **看懂設備：** 知道每個機構、馬達、相機、感測器及光學元件的用途。
2. **看懂製程：** 知道工件從進料、定位、光學對位、點膠、固化到出料的完整流程。
3. **看懂控制：** 知道 IPC、LabVIEW、運動控制器及各種硬體之間如何溝通。
4. **看懂程式：** 能夠從 LabVIEW Front Panel 追蹤到 Block Diagram，理解各個 SubVI 的功能。
5. **能夠修改程式：** 面對傳承光電提出的新需求時，知道應該修改哪個功能模組，以及如何驗證修改結果。

## 二、課程正式規劃

我們依照以下順序進行：

| 課程 | 主題 | 學習重點 |
|---|---|---|
| 01 | 設備整體架構 | 認識 Dual LD Lens Active Aligner |
| 02 | 機械結構 | 平台、滑軌、螺桿、夾具、取放料 |
| 03 | 運動控制 | 軸、馬達、驅動器、位置控制 |
| 04 | 光學基礎 | LD、Lens、PIC、光纖、光耦合 |
| 05 | Machine Vision | 相機取像、辨識、座標與角度計算 |
| 06 | Active Alignment | 光功率回授與最佳位置搜尋 |
| 07 | Auto Load / Unload | 自動上下料及安全互鎖 |
| 08 | 點膠與 UV 固化 | 點膠機構、固化及品質檢查 |
| 09 | LabVIEW 基礎 | Front Panel、Block Diagram、Dataflow |
| 10 | LabVIEW 控制架構 | State Machine、SubVI、Error Handling |
| 11 | 硬體通訊 | 運動控制器、Camera、Power Meter、I/O |
| 12 | 既有專案分析 | 讀懂實際 LabVIEW 專案 |
| 13 | 客製化功能開發 | 依照客戶需求修改及驗證 |

每一課都會包含：
- 原理說明。
- 實際設備應用情境。
- 圖解或流程圖。
- 小測驗。
- 依照你的回答找出理解上的盲點，再逐步補強。

## 三、我們會特別注意一件事

GMT 官網的設備規格，只能作為我們認識設備的起點。

未來取得實際 LabVIEW 專案後，我們必須重新確認：

- 實際使用幾個運動軸？
- 是否使用雙組六軸定位系統？
- Camera 的型號與數量是否相同？
- 光功率計是否仍使用官網列出的 Keithley 型號？
- Auto Load 是 Tray、Robot、電動夾爪，還是其他機構？
- IPC 如何與運動控制器及其他設備通訊？

**我們不會把官網規格直接當成實機規格。**

---

## 四、正式開始：第一課

下一步，我們先從：

**第一課：GMT Dual LD Lens Active Aligner 的整體設備架構**

開始。

這一課不急著看 LabVIEW，也不急著研究程式碼。我們先建立一個完整概念：

**一台機器如何把兩個 Lens 放到正確的位置，透過相機與光功率找到最佳光學耦合位置，最後固定成品？**

這個流程理解之後，再進入各個子系統，你就不會只是記住零件名稱，而是能理解整台機器為什麼需要這些零件，以及它們如何互相配合。

我們就按照這個方向，一次學好一個部分。

---

你提出的問題非常重要。我先告訴你一個結論：

**你理解的工作流程大致正確，但有一個關鍵觀念需要調整：LabVIEW 程式不是一般的文字程式碼，因此不能像 STM32 的 C/C++ 專案一樣，直接使用 VS Code 編輯 LabVIEW 程式。**

不過，你完全可以使用自己的電腦進行 LabVIEW 開發，再將完成的程式部署到設備 IPC 上。

我從頭解釋，先不用擔心你完全不懂 LabVIEW，這正是我們現在要建立的基礎。

# 一、先認識 LabVIEW 是什麼

你過去使用 STM32、C++，應該很熟悉這種程式開發方式：

```cpp
int main()
{
    Initialize();

    while (1)
    {
        ReadSensor();
        ControlMotor();
    }
}
```

這是文字型程式語言。

而 LabVIEW 不一樣。

LabVIEW 是由 NI（National Instruments）開發的**圖形化程式設計環境**，使用 G 語言（Graphical Programming Language）。

它不是以文字指令為主要形式，而是透過圖形方塊、連線和資料流來建立程式。[NI](https://www.ni.com/docs/ca-AD/bundle/labview/page/labview-overview.html?utm_source=chatgpt.com)

例如：

**C++ 的概念：**

```cpp
ReadSensor();
ControlMotor();
```

**LabVIEW 的概念：**

```text
┌──────────────┐
│ Read Sensor  │
└──────┬───────┘
       │ 資料線
       ▼
┌──────────────┐
│ Control Motor│
└──────────────┘
```

實際在 LabVIEW 裡面，這些方塊稱為 Function 或 SubVI，方塊之間透過線路傳遞資料。

LabVIEW 程式主要有兩個重要畫面：



| 畫面 | 名稱 | 功能 |
|---|---|---|
| 操作畫面 | Front Panel | 操作人員看到的按鈕、數值、狀態、圖表 |
| 程式畫面 | Block Diagram | 真正的控制邏輯與程式流程 |

這一點很重要：

**LabVIEW 的 Block Diagram 才是我們未來要學習與修改的主要程式內容。**

---

# 二、VS Code 能不能編輯 LabVIEW？

答案是：**不能直接編輯 LabVIEW 的主要圖形程式。**

我們比較一下：

| 開發項目 | STM32 C/C++ | LabVIEW |
|---|---|---|
| 程式語言 | C/C++ | G 語言 |
| 主要程式形式 | 文字程式碼 | 圖形方塊與連線 |
| 開發工具 | VS Code、STM32CubeIDE 等 | LabVIEW IDE |
| 程式檔案 | `.c`、`.cpp`、`.h` | `.vi` |
| 專案檔案 | `.project`、CMake 等 | `.lvproj` |
| 建立執行程式 | Compiler / Linker | Application Builder |

所以，即使你的電腦安裝了 VS Code，也不能直接打開 `.vi` 檔案，像編輯 `.cpp` 一樣修改裡面的 Block Diagram。

你可以把 VS Code 留著，未來它仍然能用於編輯輔助程式、文字設定檔、Python、C++ 等，但 LabVIEW 的主要開發工作必須使用 LabVIEW IDE。

---

# 三、你自己的電腦如何連接機台 IPC？

這才是你真正關心的問題。

我認為有兩種可行的開發方式。

## 方式 A：透過遠端桌面，直接操作 IPC

假設 GMT 機台內部有一台 IPC（Industrial PC，工業電腦），上面安裝了 Windows 和 LabVIEW。

你可以透過網路連線到 IPC。

架構如下：

```text
┌──────────────────────────┐
│       你的工程電腦        │
│                          │
│        Windows           │
│                          │
│       VS Code            │
│                          │
│   遠端桌面連線程式        │
└────────────┬─────────────┘
             │
             │ Ethernet LAN
             │
             ▼
┌──────────────────────────┐
│       GMT 機台 IPC        │
│                          │
│       Windows            │
│                          │
│       LabVIEW IDE        │
│                          │
│       LabVIEW 專案       │
│                          │
│       Application Builder│
└────────────┬─────────────┘
             │
             ▼
       運動控制器
       Camera
       Power Meter
       I/O
       其他設備
```

你在自己的電腦上操作遠端桌面，就像坐在 IPC 前面一樣。

如果 IPC 有安裝 LabVIEW Development Environment，你就可以在 IPC 上直接開啟 LabVIEW 專案，查看 Front Panel、Block Diagram，進行修改。

但要注意：

- IPC 必須允許遠端連線。
- 公司 IT 或設備管理者必須允許這種連線方式。
- IPC 必須安裝 LabVIEW 開發環境，而不只是執行環境。
- 必須取得原始 LabVIEW 專案與 VI 檔案。

**這種方式不代表你要用 VS Code 編輯 LabVIEW，而是透過自己的電腦遠端操作 IPC 上的 LabVIEW IDE。**

## 方式 B：在自己的電腦安裝 LabVIEW，自己開發

我反而認為，這是值得我們優先規劃的方式。

例如：

```text
┌──────────────────────────┐
│       你的工程電腦        │
│                          │
│       LabVIEW IDE        │
│                          │
│       LabVIEW Project    │
│                          │
│       修改程式            │
│                          │
│       Build EXE          │
└────────────┬─────────────┘
             │
             │ Ethernet / Network
             │
             ▼
┌──────────────────────────┐
│       GMT 機台 IPC       │
│                          │
│       Windows            │
│                          │
│       LabVIEW Runtime    │
│                          │
│       執行設備程式        │
└──────────────────────────┘
```

這個方式的工作流程是：

1. 在自己的電腦安裝 LabVIEW。
2. 從 IPC 或公司專案儲存位置取得完整 LabVIEW 專案。
3. 在自己的電腦開啟 `.lvproj`。
4. 查看並修改 `.vi`。
5. 在自己的電腦進行程式測試。
6. 使用 LabVIEW Application Builder 建立 EXE。
7. 將測試完成的執行檔部署到 IPC。
8. 在 IPC 上執行，確認設備功能正常。

這樣，你就不需要每次修改程式都直接進入機台 IPC。

不過，這個方式有幾個必要條件：

- 你的電腦與 IPC 使用相容的 LabVIEW 版本。
- 需要相同或相容的第三方工具包、驅動程式及硬體 API。
- 必須取得完整的原始專案。
- 需要確認 Application Builder 的授權。
- 真正連接機台硬體測試時，仍然需要依照設備安全程序進行。

尤其是 GMT 設備可能使用特定相機、運動控制器及光功率計，這些硬體的驅動程式與軟體套件也必須確認。

---

# 四、你說的「透過 IPC 內的 LabVIEW 編譯，產生執行檔」正確嗎？

你的想法基本正確，但我補充一個重要觀念。

LabVIEW 的開發與部署通常分成兩個階段：

### 第一階段：開發程式

使用 LabVIEW IDE 編輯：

- Front Panel
- Block Diagram
- SubVI
- Project
- 控制流程

這些是原始開發內容。

### 第二階段：建立執行檔

使用 LabVIEW 的 **Application Builder** 建立獨立執行程式。

例如：

```text
LabVIEW 原始專案
       │
       ├── Main.vi
       ├── Motor.vi
       ├── Camera.vi
       ├── Alignment.vi
       └── Load.vi
              │
              ▼
      Application Builder
              │
              ▼
       Machine_Control.exe
              │
              ▼
          IPC 執行
```

NI 官方文件說明，可以透過 LabVIEW 專案中的 `Build Specifications → New → Application (EXE)` 建立獨立執行檔。

但建立 EXE 需要 Application Builder 授權；而執行 EXE 的 IPC 通常需要安裝相對應版本的 LabVIEW Runtime Engine。[NI](https://www.ni.com/docs/sq-AL/bundle/labview/page/creating-stand-alone-applications.html?utm_source=chatgpt.com)

所以，還有一個重要差異：

| 軟體 | 用途 |
|---|---|
| LabVIEW Development Environment | 開發、查看及修改程式 |
| LabVIEW Application Builder | 建立 EXE |
| LabVIEW Runtime Engine | 執行已建立的 EXE |

**IPC 不一定需要安裝完整 LabVIEW 開發環境。**

有些設備 IPC 只安裝 Runtime Engine，負責執行已經建立好的 EXE。

這也代表，即使你可以遠端連接 IPC，也不代表你一定能在 IPC 上修改原始程式。

---

# 五、我建議你未來採用的工作模式

考量你會接手既有程式，也可能需要依照傳承光電的需求新增功能，我建議採取：

**自己的電腦作為主要開發環境，IPC 作為設備執行與整合測試環境。**

但在真正確認 GMT 的開發環境之前，我們不先假設它一定可以這樣運作。

理想架構如下：

```text
             開發階段
                 │
                 ▼
       ┌──────────────────┐
       │    你的電腦       │
       │                  │
       │ LabVIEW IDE      │
       │ 原始專案          │
       │ 修改與測試        │
       │ Application      │
       │ Builder          │
       └────────┬─────────┘
                │
                │ 部署 EXE
                ▼
       ┌──────────────────┐
       │     GMT IPC      │
       │                  │
       │ LabVIEW Runtime  │
       │ Machine EXE      │
       └────────┬─────────┘
                │
                ▼
          實際設備控制
```

另外，設備控制程式有一點要特別注意：不能只因為 EXE 成功啟動，就認定機台可以正常運作。必須確認軸控制、相機、光功率量測、氣動、真空及安全互鎖都正常。

---

# 六、正式開始第一課前，我想先確認三件事情

目前我們還沒看到 GMT 實機，也不知道 IPC 的軟體配置。

因此，先不用安裝任何軟體，也不用連接機台。

我只想確認三件事：

1. **你的個人電腦是 Windows 11 嗎？** 我們未來可以評估在自己的電腦安裝 LabVIEW 開發環境。
2. **你是否可以取得 GMT IPC 的 Windows 管理權限，或至少能夠使用遠端桌面？** 這會影響我們如何取得專案及部署程式。
3. **你是否知道 GMT 目前有沒有提供 LabVIEW 原始專案（`.lvproj`、`.vi`），還是只有已經安裝在 IPC 裡面的執行程式？**

第三點尤其重要。

如果只有 EXE，通常不能直接還原成原始 Block Diagram。NI 官方也明確說明，使用 Application Builder 預設設定建立的 EXE，無法直接取回原始 Block Diagram。[knowledge.ni.com](https://knowledge.ni.com/KnowledgeArticleDetails?id=kA00Z0000019NfnSAE\&l=en-US\&utm_source=chatgpt.com)

所以，我們未來接手工作的第一件事，不是修改程式，而是確認是否能取得**完整的 LabVIEW 原始專案**。

這是避免後續開發受阻的關鍵。

你可以先回答這三點，我們再決定最適合你的 LabVIEW 開發環境。

---

可以，而且你的情況其實很適合先研究這種方式。

**你的 Windows 11 專業版電腦，可以透過一條 Ethernet 網路線，直接連接 GMT 機台的 IPC，不需要連上公司的網際網路，也不一定需要第三方軟體。**

我們先把這件事弄清楚。這個技術叫做 **Remote Desktop（遠端桌面，RDP）**。

---

# 一、先理解連線架構

假設 GMT 機台內有一台 IPC，IPC 使用 Windows 作業系統，並且安裝了 LabVIEW。

我們可以建立以下連線：

```text
       你的 Windows 11 電腦
       ┌──────────────────┐
       │                  │
       │  Windows 11 Pro  │
       │                  │
       │  Remote Desktop  │
       │  Connection      │
       │                  │
       └────────┬─────────┘
                │
                │
          Ethernet 網路線
                │
                │
       ┌────────┴─────────┐
       │                  │
       │    GMT IPC       │
       │                  │
       │  Windows         │
       │                  │
       │  LabVIEW IDE     │
       │                  │
       │  LabVIEW Project │
       │                  │
       └──────────────────┘
```

注意：

這條網路線只負責讓兩台電腦互相通訊。

**不需要公司網路、不需要 Internet，也不需要 Wi-Fi。**

兩台電腦只要設定在相同的 IP 網段，就可以互相通訊。

不過，公司對機台網路有嚴格管制，因此實際連接前仍應取得設備或 IT 管理者許可。

---

# 二、連線後會看到什麼畫面？

這是 Remote Desktop 的概念：



假設你成功連線：

你的電腦螢幕就會顯示 GMT IPC 的 Windows 桌面。

例如：

```text
┌──────────────────────────────────────────────┐
│  你的 Windows 11 電腦                         │
│                                              │
│  ┌────────────────────────────────────────┐  │
│  │ Remote Desktop - GMT IPC               │  │
│  │                                        │  │
│  │  GMT IPC 的 Windows 桌面               │  │
│  │                                        │  │
│  │  ┌────────────┐   ┌───────────────┐    │  │
│  │  │ LabVIEW    │   │ Machine       │    │  │
│  │  │ Project    │   │ Control.exe   │    │  │
│  │  └────────────┘   └───────────────┘    │  │
│  │                                        │  │
│  │  此處顯示的是 IPC 真正的桌面            │  │
│  └────────────────────────────────────────┘  │
│                                              │
└──────────────────────────────────────────────┘
```

你可以：

- 使用滑鼠操作 IPC。
- 使用鍵盤輸入。
- 開啟 IPC 裡面的 LabVIEW。
- 查看原始 `.vi` 程式（前提是有開發環境及原始檔）。
- 開啟檔案總管。
- 查看設備程式及設定檔。

這不是單純的螢幕投影，而是遠端控制另一台電腦。

---

# 三、需要安裝第三方軟體嗎？

**如果 IPC 使用 Windows Pro、Enterprise 或支援 RDP 的 Windows Server，通常不需要。**

Windows 本身已經內建遠端桌面功能。

我們需要認識兩個角色：

| 角色 | 電腦 | 功能 |
|---|---|---|
| RDP Client | 你的 Windows 11 | 發起遠端連線 |
| RDP Host | GMT IPC | 接受遠端連線 |

Microsoft 官方文件說明：

- 遠端被連線的電腦必須支援 Remote Desktop Host。
- Windows 11 Pro 可以作為遠端桌面 Host。
- 發起連線的電腦不論 Windows Home 或 Pro 都可以。[Microsoft 支援](https://support.microsoft.com/en-gb/windows/experience/connectivity-networking/how-to-use-remote-desktop?utm_source=chatgpt.com)

你可以使用 Windows 內建的：

**Remote Desktop Connection（遠端桌面連線）**

開啟方式：

1. 按下 `Win + R`。
2. 輸入：

```text
mstsc
```

3. 按 Enter。

就會出現 Windows 內建的遠端桌面連線視窗。

---

# 四、實際上如何用網路線連接？

這裡是最重要的部分。

假設：

| 設備 | IP 位址 |
|---|---|
| 你的電腦 | 192.168.50.10 |
| GMT IPC | 192.168.50.20 |
| 子網路遮罩 | 255.255.255.0 |

這只是示範用 IP，**不是 GMT IPC 的實際 IP**。

## Step 1：連接網路線

將網路線：

```text
你的電腦 Ethernet Port
          │
          │ 網路線
          │
GMT IPC Ethernet Port
```

直接連接。

現在大部分 Ethernet 網卡都支援 Auto MDI-X，通常不需要特殊交叉網路線。

## Step 2：設定你的電腦 IP

在 Windows 11：

```text
設定
  ↓
網路和網際網路
  ↓
乙太網路
  ↓
IP 指派
  ↓
編輯
  ↓
手動
  ↓
IPv4
```

設定示範：

```text
IP Address：      192.168.50.10
Subnet Mask：     255.255.255.0
Default Gateway： 留空
DNS：             留空
```

這樣你的電腦就有一個獨立的區域網路 IP。

## Step 3：確認 IPC IP

GMT IPC 也必須設定在相同網段。

例如：

```text
IP Address：      192.168.50.20
Subnet Mask：     255.255.255.0
```

但這個設定必須先確認 IPC 現有網路配置。

**不要直接更改 GMT IPC 的 IP。**

因為 IPC 可能還連接著運動控制器、相機、PLC 或其他設備。隨意更改 IP 可能造成設備通訊中斷。

## Step 4：測試兩台電腦是否通訊

在你的電腦開啟 PowerShell：

```powershell
ping 192.168.50.20
```

如果成功，可能看到：

```text
Reply from 192.168.50.20:
bytes=32 time<1ms TTL=128
```

這表示兩台電腦之間的 IP 通訊正常。

## Step 5：啟動遠端桌面

在 GMT IPC 上，需要由有權限的人員確認：

```text
設定
  ↓
系統
  ↓
遠端桌面
  ↓
啟用遠端桌面
```

另外還需要：

- 允許你的 Windows 帳號登入。
- Windows 防火牆允許 RDP。
- IPC 沒有被公司政策禁止遠端桌面。

RDP 預設使用 TCP 3389，但不應為了連線而擅自關閉防火牆或開放不必要的連接埠。[Microsoft Learn](https://learn.microsoft.com/en-us/windows-server/remote/remote-desktop-services/remotepc/remote-pc-connections-faq/?utm_source=chatgpt.com)

## Step 6：從你的電腦連線

在你的 Windows 11：

按 `Win + R`。

輸入：

```text
mstsc
```

出現視窗後，輸入：

```text
192.168.50.20
```

按下「連線」。

接著輸入 IPC 的 Windows 帳號與密碼。

如果成功，你就會看到 GMT IPC 的 Windows 桌面。

---

# 五、這個方法有一個重要限制

我特別提醒你。

**Remote Desktop 不等於直接連接 LabVIEW，也不代表可以同時讓 IPC 螢幕與你的電腦螢幕操作同一個桌面。**

一般 Windows RDP 登入可能會切換或鎖定 IPC 的本機互動工作階段。

對於正在控制機台的 IPC，這是非常重要的問題。

例如：

```text
GMT IPC 正在執行機台控制程式
             │
             ▼
你從自己的電腦 RDP 登入
             │
             ▼
IPC 可能切換使用者工作階段
             │
             ▼
原本機台操作畫面可能受到影響
```

因此，**不能在設備運轉時，未經確認就使用 RDP 登入。**

如果機台要求本機操作畫面持續顯示，可能需要由 GMT 評估其他遠端協助方式，例如只共享螢幕、不切換本機工作階段的遠端控制工具。

另外，公司若禁止未核准的遠端存取，即使是直接接網路線，也必須先取得許可。

---

# 六、我建議我們先做一個小實驗

在真正接觸 GMT 機台以前，我們可以先用兩台一般 Windows 電腦練習。

這樣你就會真正理解：

1. 什麼是 IP Address。
2. 什麼是 Subnet Mask。
3. 兩台電腦如何透過網路線通訊。
4. 如何使用 `ping`。
5. 如何使用 `mstsc`。
6. 成功連線後如何操作另一台電腦。

這些能力未來不只適用於 LabVIEW，也適用於你之前接觸的 Raspberry Pi CM5、STM32 Ethernet、TCP/IP 等系統。

---

## 七、現在先確認一件事

我不希望我們一次做太多。

請先告訴我：

**你的 Windows 11 電腦目前有沒有實體 RJ45 網路孔，可以直接插入 Ethernet 網路線？**

如果有，我們下一步就可以先在你的電腦上進行唯讀檢查，確認網路卡、目前 IP 設定及網路介面狀態。

先不修改任何網路設定，也不連接 GMT IPC。

Microsoft 官方操作說明：[Windows 11 遠端桌面使用教學](https://support.microsoft.com/en-gb/windows/experience/connectivity-networking/how-to-use-remote-desktop?utm_source=chatgpt.com)。


---

# 第一課：GMT Dual LD Lens Active Aligner 整體設備架構

這一課先不談 LabVIEW 程式，也不深入馬達或相機的細節。

我們的目標是先建立一個完整概念：

**這台設備要完成什麼工作？有哪些主要機構？各機構如何合作？LabVIEW 在整台設備中負責什麼？**

先理解這些，未來看到實際機台或 LabVIEW 專案時，才不會只看到一堆馬達、相機、I/O 和程式方塊，卻不知道它們為什麼存在。

---

## 一、這台設備的主要任務是什麼？

我們目前研究的候選設備是 GMT 的：

****

從 GMT 公開資料來看，這台設備主要是要完成：

**將兩個 Lens（透鏡）精確地對準 PIC（光子積體電路），讓光訊號能夠有效地耦合進入 PIC，最後使用 UV Glue（紫外線膠）固定透鏡。**

這裡有幾個重要名詞：

| 名稱 | 英文 | 初步理解 |
|---|---|---|
| LD | Laser Diode | 雷射二極體，光訊號來源之一 |
| Lens | Lens | 透鏡，用來聚焦或調整光線 |
| PIC | Photonic Integrated Circuit | 光子積體電路，可以理解為處理光訊號的積體電路 |
| Active Alignment | 主動對位 | 一邊調整位置，一邊測量光功率，找出最佳位置 |
| UV Glue | UV-curable Adhesive | 紫外線固化膠，用來固定已對準的零件 |

### 為什麼需要 Active Alignment？

想像一下：

你手上有一個透鏡，必須把它放到 PIC 上方的正確位置。

如果透鏡偏左、偏右、太高、太低，或者角度不正確，光線就可能無法有效進入 PIC。

問題是：

**我們不能只靠肉眼判斷透鏡的位置是否正確。**

因此，設備需要一邊移動透鏡，一邊測量光功率。

例如：

| 透鏡位置 | 測量到的光功率 |
|---|---:|
| 位置 A | 0.5 mW |
| 位置 B | 1.2 mW |
| 位置 C | 2.8 mW |
| 位置 D | 2.1 mW |

這時候可以知道，位置 C 的光功率最高。

設備就能利用這些量測結果，尋找最佳的對位位置。

這就是 Active Alignment 最重要的概念：

**不是單純把零件移到指定座標，而是透過實際光學量測，找出光耦合效果最好的位置。**

---

## 二、整台設備可以分成哪些主要部分？

先把設備想像成一條自動化生產線。

它不是只有一個平台和幾顆馬達，而是由多個模組合作完成工作。

依照 GMT 公開規格，我們可以先整理成以下架構。



### 1. Auto Loading / Unloading（自動上下料）

這個模組負責：

- 將尚未加工的 Lens 放入設備。
- 將待加工的 PCB 或 PIC 放入設備。
- 把零件送到指定加工位置。
- 加工完成後，將產品移出。
- 將完成品放到指定位置。

GMT 公開規格提到 Lens Loading Tray，以及 PCB Tray。

你可以先把它想成：

**負責把原料送進來，並把完成品送出去的自動化搬運系統。**

主管提到的「Auto Load」，很可能就是與這部分有關。

但客戶實際使用的上下料方式，還需要等看到機台才能確認。

### 2. Vision System（視覺系統）

這個模組使用 Camera 拍攝零件。

主要用途可能包括：

- 確認 Lens 是否放在正確位置。
- 確認 PCB/PIC 的位置。
- 辨識零件特徵。
- 協助計算零件的中心位置與角度。
- 提供後續對位所需的初始座標。

GMT 公開規格提到使用兩台 Camera。

這裡先建立一個觀念：

**Camera 負責觀察和辨識，但不代表 Camera 自己會移動零件。**

它提供影像資訊，後續仍需要運動機構執行調整。

第三課以後，我們會再深入理解 Camera、影像辨識和座標轉換。

### 3. Precision Alignment Stage（精密對位平台）

這是整台設備非常重要的部分。

它負責實際移動 Lens 或工件，進行精密對位。

GMT 公開規格提到：

- Dual 6-axis System。
- 高精度 XYZ 運動平台。
- Step Motor（步進馬達）。
- Ball Screw（滾珠螺桿）。
- 高精度位置調整。

你可以先這樣理解：

Camera 告訴系統目前零件在哪裡，光功率量測告訴系統目前耦合效果如何，而對位平台負責實際移動零件。

**它是執行位置調整的機械手腳。**

注意：公開規格中的 Dual 6-axis System，不能直接解讀為整台機台一定有 12 個獨立控制軸，實際軸數必須等取得機台配置後確認。

### 4. Dispensing System（點膠系統）

Lens 對準後，需要使用 UV Glue 固定。

因此設備有精密點膠機構。

主要工作：

1. 將膠水送到指定位置。
2. 控制膠水的用量。
3. 確保膠水分布符合製程要求。

這裡要注意：

點膠不是隨便把膠水塗上去。

膠量、位置及點膠時間，都可能影響最終產品品質。

### 5. UV Curing System（紫外線固化系統）

點膠完成並且確認對位後，需要利用 UV 光照射膠水，使膠水固化。

GMT 公開資料提到：

- HOYA LED。
- 365nm UV 光源。
- 四組 UV LED。

可以先把它理解成：

**點膠負責放置固定材料，UV Curing 負責讓固定材料硬化。**

實際的照射時機、時間和光強度，必須依照客戶製程設定。

### 6. Power Meter（光功率量測設備）

這是 Active Alignment 的關鍵。

設備需要知道：

目前 Lens 的位置是否讓光訊號有效進入 PIC？

因此需要 Power Meter（光功率計）測量光功率。

GMT 公開規格提到 Keithley E3646A，但也註明可以依需求修改。

這個設備提供量測數據，讓控制系統知道目前對位效果。

---

## 三、這些模組如何合作？

現在把剛才的六個部分串起來。

先看一個簡化的製程流程：

```text
        開始
          │
          ▼
  Auto Loading 自動上料
          │
          ▼
  Vision System 相機取像
          │
          ▼
  辨識 Lens / PCB / PIC 位置
          │
          ▼
  將工件固定在加工平台
          │
          ▼
  Dispensing 精密點膠
          │
          ▼
  Alignment Stage 精密對位
          │
          ▼
  Power Meter 測量光功率
          │
          ▼
  是否達到最佳對位條件？
       ┌──┴──┐
       │     │
      否     是
       │     │
       ▼     ▼
  繼續調整  UV Curing
       │     │
       └─回到 │
       對位   ▼
           固化完成
              │
              ▼
       檢查製程結果
              │
              ▼
       Auto Unloading
              │
              ▼
             結束
```

這是一個用來理解設備的簡化流程，並不是已確認的 Formerica 客戶正式製程。

例如，實際設備可能會先完成部分對位，再點膠，接著進行最終 Active Alignment。這個順序要以實際製程為準。

---

## 四、LabVIEW 在整台設備中扮演什麼角色？

這是你未來工作最需要理解的部分。

先想像：

整台設備有很多硬體：

- 馬達。
- 相機。
- 光功率計。
- 點膠機。
- UV LED。
- 氣壓缸。
- 真空吸附。
- 感測器。
- 安全門。

如果每個硬體都各自運作，設備就無法按照正確的製程完成工作。

因此，需要一個控制系統負責協調它們。

這就是 LabVIEW 在這台設備中的重要角色。

### LabVIEW 可以負責哪些工作？

| 工作 | LabVIEW 的角色 |
|---|---|
| 操作畫面 | 顯示設備狀態、按鈕、參數 |
| 自動製程 | 按照製程順序執行各個步驟 |
| 馬達控制 | 發出運動命令或透過控制器操作馬達 |
| Camera | 觸發取像、接收影像辨識結果 |
| Power Meter | 取得光功率量測值 |
| 點膠 | 控制點膠設備或相關 I/O |
| UV Curing | 控制 UV 照射 |
| 安全檢查 | 確認門鎖、氣壓、真空等條件 |
| 資料紀錄 | 儲存產品參數、量測結果及生產紀錄 |

要特別注意：

**LabVIEW 不一定直接控制每一顆馬達。**

例如，實際架構可能是：

```text
              IPC
               │
            LabVIEW
               │
       ┌───────┼────────┐
       │       │        │
       ▼       ▼        ▼
   運動控制器  Camera  Power Meter
       │
       ▼
    馬達驅動器
       │
       ▼
      馬達
```

LabVIEW 負責發出命令、協調流程和處理結果。

運動控制器負責執行馬達的位置控制。

馬達驅動器負責驅動馬達。

這些設備各自有不同的工作，不應該混為一談。

未來我們拿到實際 IPC 專案時，就要確認它到底使用哪種控制器、通訊方式和硬體架構。

---

## 五、用一個實際情境理解整台設備

假設現在要加工一個產品，需要把兩個 Lens 對準 PIC。

我們模擬一次設備運作：

**第一步：上料**

操作人員把 Lens Tray 和 PCB Tray 放入設備。

按下自動啟動後，Auto Loading 模組開始工作。

**第二步：視覺定位**

Camera 拍攝 Lens 和 PCB/PIC。

系統透過影像辨識，取得零件目前的位置。

**第三步：固定工件**

設備利用夾具或真空吸附，將工件固定在加工平台上。

**第四步：點膠**

Dispensing System 在指定位置點上 UV Glue。

**第五步：主動對位**

運動平台開始移動 Lens。

Power Meter 持續量測光功率。

例如：

```text
移動位置 A → 光功率 0.5 mW
移動位置 B → 光功率 1.2 mW
移動位置 C → 光功率 2.8 mW
移動位置 D → 光功率 3.5 mW
移動位置 E → 光功率 3.1 mW
```

系統發現位置 D 的光功率最高。

因此，它可能將位置 D 作為目前最佳候選位置，再依照製程條件確認是否達到要求。

**第六步：UV 固化**

確認對位結果符合條件後，啟動 UV LED，讓膠水固化。

**第七步：完成與紀錄**

系統記錄量測結果、加工參數和產品資訊。

最後由 Auto Unloading 模組將完成品移出。

這整個過程，就是一台自動化 Active Aligner 的基本工作概念。

---

## 六、本課最重要的觀念整理

今天先記住以下五件事：

1. **Auto Loading / Unloading**：負責搬運工件。
2. **Vision System**：負責拍攝影像、辨識零件位置。
3. **Alignment Stage**：負責實際移動零件。
4. **Power Meter**：負責測量光功率，提供對位效果的依據。
5. **LabVIEW**：負責協調各個硬體，按照製程順序完成自動化工作。

其中最重要的是理解這個關係：

**Camera 提供位置資訊 → 運動平台移動零件 → Power Meter 回報光功率 → 控制系統根據結果決定下一步。**

這是 Active Alignment 的核心概念。

---

# 七、第一課小測驗

接下來請你回答三個問題。我會根據你的回答判斷哪些觀念已經理解，哪些地方還需要補強。

### 第 1 題：Vision System

Camera 拍攝到 Lens 的影像，系統辨識出 Lens 目前偏右側 0.2mm。

請問：

A. Camera 自己會把 Lens 移回正確位置。

B. Camera 提供位置資訊，再由運動平台移動 Lens。

C. Power Meter 直接控制 Camera 移動 Lens。

### 第 2 題：Active Alignment

為什麼設備不能只依靠 Camera 拍攝到的位置，就判定 Lens 已經對準？

A. 因為 Camera 無法拍攝 Lens。

B. 因為影像位置正確，不代表實際光耦合效率一定最佳，還需要光功率量測。

C. 因為馬達不能按照 Camera 的資訊移動。

### 第 3 題：LabVIEW

假設 LabVIEW 下達命令，要求 Lens 移動 0.1mm。

請問下列哪個描述比較合理？

A. LabVIEW 一定直接提供馬達所需的電流。

B. LabVIEW 可以將運動命令交給運動控制器，再由驅動器驅動馬達。

C. Power Meter 負責讓馬達移動 0.1mm。

---

請直接回答：

```text
第 1 題：
第 2 題：
第 3 題：
```

答完後，我會逐題批改，並針對容易混淆的地方補充說明。通過這一課後，我們再進入第二課：**機械結構——平台、滑軌、滾珠螺桿、夾具與自動上下料機構。**


---

三題全部答對！🎉

而且你的回答不只是記住名詞，而是已經掌握三個重要的系統關係：

1. **Camera → 運動平台**：Camera 提供位置資訊，運動平台負責實際移動。
2. **影像定位 → 光功率驗證**：影像位置正確，不代表光耦合效果最佳，因此需要 Power Meter 回授。
3. **LabVIEW → 運動控制器 → 驅動器 → 馬達**：LabVIEW 可以負責協調與下達運動命令，不一定直接控制馬達。

第一課的小測驗通過！接下來回答你提出的 EtherCAT 問題。

# LabVIEW 專案還需要 EtherCAT 嗎？

**不一定。使用 LabVIEW 並不代表不需要 EtherCAT，也不代表一定需要 EtherCAT。**

這裡有一個很重要的觀念：

- **LabVIEW 是控制軟體／開發平台。**
- **EtherCAT 是工業即時通訊技術。**

兩者並不是互相取代的關係。

LabVIEW 可以透過不同的通訊方式控制硬體，EtherCAT 只是其中一種可能。

## 一、先看三種可能的架構

### 架構 A：LabVIEW 直接控制運動控制器

```text
       IPC
        │
     LabVIEW
        │
   USB / Ethernet
        │
   運動控制器
        │
     驅動器
        │
      馬達
```

這種情況下，運動控制器可能使用廠商提供的 API、SDK 或通訊協定。

不一定需要 EtherCAT。

### 架構 B：LabVIEW 透過 EtherCAT 控制

```text
       IPC
        │
     LabVIEW
        │
  EtherCAT Master
        │
    EtherCAT
        │
   ┌────┼────┐
   ▼    ▼    ▼
 Servo Servo Servo
 Drive Drive Drive
   │    │    │
 Motor Motor Motor
```

這種情況下，IPC 或其他控制器必須具有 EtherCAT Master 功能。

LabVIEW 負責上層製程控制，EtherCAT 負責即時控制資料交換。

### 架構 C：LabVIEW + PLC + EtherCAT

```text
        IPC
         │
      LabVIEW
         │
       Ethernet
         │
         PLC
         │
      EtherCAT
         │
    ┌────┼────┐
    ▼    ▼    ▼
  Servo Servo Servo
  Drive Drive Drive
```

這種情況下，LabVIEW 不直接處理 EtherCAT，而是透過 PLC 下達命令。

PLC 負責運動控制及設備 I/O。

---

## 二、回到 GMT Dual LD Lens Active Aligner

GMT 公開規格提供了一些線索：

| 項目 | 公開規格 |
|---|---|
| 軟體程式語言 | LabVIEW |
| 運動機構 | Step Motor + Ball Screw |
| Alignment Module | Dual 6-axis System |
| Camera | 2 台 |
| Power Meter | Keithley E3646A |
| UV Curing | HOYA LED |

但這份規格沒有明確說明：

- 使用哪一家運動控制器？
- 使用哪一種馬達驅動器？
- 是否使用 PLC？
- 是否使用 EtherCAT？
- EtherCAT Master 是 IPC、PLC 還是獨立控制器？

所以目前還不能判定這台設備有沒有使用 EtherCAT。

另外，規格寫的是 Step Motor（步進馬達），不能因此就認定它沒有 EtherCAT。步進馬達也可以搭配支援 EtherCAT 的驅動器。

## 三、這對你接下來的工作有什麼影響？

你以前在 STM32H755 專案中接觸的架構是：

```text
STM32H755
     │
     ▼
EtherCAT Master Module
     │
     ▼
EtherCAT Slave Servo Drives
     │
     ▼
    馬達
```

而現在的 LabVIEW 專案可能是：

```text
IPC
 │
 ▼
LabVIEW
 │
 ▼
運動控制器
 │
 ▼
馬達驅動器
 │
 ▼
馬達
```

你會發現，**上層控制流程的概念很相似，只是底層硬體架構和通訊方式可能不同。**

因此，你以前學過的運動控制、位置命令、軸控制、回授等概念仍然有價值，不會因為改用 LabVIEW 就全部失去作用。

---

## 四、未來拿到實機時，最值得先確認的東西

我建議先確認一項：

**這台機台的運動控制器是哪一個品牌及型號？**

因為只要知道控制器型號，通常就能進一步確認：

- 是否使用 EtherCAT。
- 是否使用 PCIe 運動控制卡。
- 是否透過 Ethernet 通訊。
- 是否使用 USB。
- LabVIEW 是透過 DLL、API、SDK 還是其他方式控制它。

這會直接影響你未來接手既有 LabVIEW 專案的方式。

**我的建議：目前先不要急著學 EtherCAT 在 LabVIEW 中如何實作。** 先把設備整體架構、機械機構、光學對位原理學好。等取得實際 IPC 和控制器資料後，再針對真正使用的通訊架構學習，避免花時間研究設備根本沒有使用的技術。


---

這份週報非常有價值。它比 GMT 官網的產品介紹更接近實際設備開發情況，因為裡面已經出現了**實際使用的硬體、通訊方式、運動控制功能、影像辨識功能，以及真正的生產流程**。

我仔細整理後，認為我們可以獲得不少線索，而且有幾個發現會直接影響你接下來學習 LabVIEW 的方向。

先講我的整體判斷：

**這個傳承專案不是單純的六軸對位設備，而是一套整合自動上下料、雙六軸運動控制、機器視覺、光功率量測、點膠與 UV 固化的自動化光學耦合設備。**

而且從週報來看，實際開發工作已經涉及相當多 LabVIEW 可能需要整合的硬體。

不過，週報沒有明確寫出程式語言和運動控制通訊協定，因此我們還不能確定所有控制功能都是由 LabVIEW 實作，也不能確認是否使用 EtherCAT。

以下分成幾個部分分析。

# 一、首先區分週報中的三個專案

這份週報其實混合了不同的工作項目，不能全部視為同一台設備。

| 專案名稱 | 主要工作 | 與你新工作的關係 |
|---|---|---|
| 傳承專案：DL 設備 | 韌體修改、雙六軸、光學對位 | 高度相關 |
| 傳承 Tx/Rx Auto Load | Tx、Rx 光學耦合與自動上下料 | 高度相關 |
| 傳承 Dual Lens Auto Load | 雙 Lens、雙六軸、點膠、UV、自動上下料 | 最值得優先研究 |
| OFC Dual Lens | 套用鴻海程式、軟體介面、硬體整合 | 可能是另一個客戶或機種的延伸 |

這裡有一個重要線索：

**週報中的「傳承 Dual Lens Auto Load」應該是我們目前最需要研究的項目。**

因為它列出了完整的設備功能和實際完成進度。

但要注意，OFC Dual Lens 與傳承 Dual Lens 是否使用相同硬體、相同程式架構，目前不能確定。

---

# 二、最重要的發現：這台設備確實有雙六軸運動控制系統

週報中有好幾項關鍵資訊：

- 六軸光學尺。
- 六軸雷干精度驗證。
- 安裝雙六軸。
- 雙六軸電腦配置。
- 雙六軸軟體配置。
- 單軸移動。
- 單軸絕對位置移動。
- 移動停止。
- 回原點。
- 緊急停止測試。
- ADC 數值確認。

這些資訊非常重要。

## 1. 什麼是雙六軸？

我們之前從 GMT 官網看到 Dual 6-axis System。

現在週報進一步證實，實際開發工作確實涉及「雙六軸」。

可以先用以下方式理解：



假設一組六軸平台包含：

| 軸 | 可能的運動方式 |
|---|---|
| X | 左右移動 |
| Y | 前後移動 |
| Z | 上下移動 |
| θX | 繞 X 軸旋轉 |
| θY | 繞 Y 軸旋轉 |
| θZ | 繞 Z 軸旋轉 |

那麼雙六軸就可以先理解為：

```text
          雙六軸系統
               │
       ┌───────┴───────┐
       │               │
       ▼               ▼
   第一組六軸       第二組六軸
       │               │
    6 個軸          6 個軸
       │               │
       ▼               ▼
   一組工件         另一組工件
   的位置調整       的位置調整
```

這是概念示意，實際兩組平台分別承載什麼零件，還需要確認。

但它代表一件事：

**你的新工作很可能會接觸到兩組獨立的精密運動平台，而不是只有一組 XYZ 平台。**

## 2. 為什麼要做六軸光學尺與雷干驗證？

週報寫到：

> 六軸光學尺，兩軸直線軸無訊號。  
> 六軸預計進行雷干精度驗證。

這透露出設備開發並不只是讓馬達可以移動，還要驗證實際運動精度。

幾個名詞：

- **光學尺（Linear Scale）**：量測平台實際移動的位置。
- **雷干（Laser Interferometer，雷射干涉儀）**：用來進行高精度位移或定位精度量測。
- **回原點（Homing）**：讓控制系統建立軸的位置參考點。
- **絕對位置移動（Absolute Move）**：移動到指定座標。
- **單軸移動（Jog）**：讓單一軸朝指定方向移動。

例如：

```text
目前 X 軸位置：0.000 mm

LabVIEW 下達：
X 軸移動到 1.000 mm

控制器執行運動
        │
        ▼
馬達帶動平台移動
        │
        ▼
光學尺回報實際位置
        │
        ▼
控制系統確認位置
```

這表示未來你很可能需要理解：

1. 軸的定義。
2. 馬達移動命令。
3. 原點設定。
4. 絕對位置與相對位置。
5. 軟體限位與硬體限位。
6. 軸狀態與錯誤處理。
7. 緊急停止。

這些內容會是第二、第三課的重要基礎。

---

# 三、目前已經可以看出實際設備有哪些硬體

這是我認為整份週報最有價值的地方。

我們可以依照週報內容，建立一份初步的硬體清單。

## 1. 運動控制系統

週報證實的項目：

- 雙六軸。
- 六軸控制電腦配置。
- 單軸移動。
- 絕對位置移動。
- 回原點。
- 移動停止。
- 緊急停止。
- ADC 數值確認。
- FDR、FLM、FRS、ERR 狀態處理。

其中 FDR、FLM、FRS 是值得注意的控制器命令或狀態名稱，但目前沒有原廠文件，不能直接判定其確切意義。

**這裡有一個很重要的線索：**

週報特別寫了「雙六軸電腦配置」，代表這套運動控制系統很可能有自己的控制硬體或控制電腦，而不只是 IPC 直接控制一般馬達驅動器。

但目前無法確認它是 PCIe 運動控制卡、獨立控制器，還是其他架構。

## 2. Camera 與視覺系統

週報寫到：

- 相機鏡頭調整 CCD1～4。
- 相機辨識功能完成。
- 修正影像辨識問題。
- Rx 影像辨識位置修正。
- Lens PR。
- FAU PR。
- PD PR。

這些線索非常明確。

這套設備至少涉及多個視覺辨識工作。

先解釋幾個名詞：

| 名稱 | 意義 | 在設備中的用途 |
|---|---|---|
| CCD | Charge-Coupled Device | 影像感測器，這裡指相機系統 |
| PR | Pattern Recognition | 圖像特徵辨識 |
| Lens PR | Lens Pattern Recognition | 辨識 Lens 位置 |
| FAU PR | Fiber Array Unit PR | 辨識光纖陣列位置 |
| PD PR | Photodiode PR | 辨識光電二極體位置 |

其中 FAU 是 Fiber Array Unit（光纖陣列單元）。

這代表設備除了 Lens 和 PIC 以外，還涉及光纖陣列相關的定位。

### CCD1～4 代表什麼？

這裡有一個值得注意的地方。

週報寫的是：

> 相機鏡頭調整 CCD1~4 調整完成。

因此可以確認至少有 CCD1 到 CCD4 這四個相機識別編號。

但不能直接認定它們都是四個不同方向的相機，或每台相機負責什麼工作。

未來需要取得相機配置表或 LabVIEW 專案中的相機初始化程式，才能確認。

---

# 四、這套設備的光學量測系統也已經有具體線索

週報提到：

> Laser、Power Meter，LAN 通訊配置。

以及：

> Rx 仍有 RSSI 讀取問題存在。

這兩句話很重要。

我們可以知道，設備不只是使用 Camera 做位置辨識，還需要實際量測光學訊號。

## 1. Laser

Laser 是雷射光源。

它可以提供光訊號，供光學耦合測試使用。

## 2. Power Meter

Power Meter 是光功率量測設備。

它用來測量光訊號的強度。

例如：

```text
Laser 發出光訊號
       │
       ▼
    Lens
       │
       ▼
   光學耦合
       │
       ▼
     FAU
       │
       ▼
  Power Meter
       │
       ▼
  回報光功率
```

這只是簡化示意，實際 Tx/Rx 的光路配置仍需確認。

## 3. RSSI 是什麼？

RSSI 全名是 Received Signal Strength Indicator。

可以先理解為：

**接收端訊號強度指標。**

週報寫：

> Rx 仍有 RSSI 讀取問題存在。

這表示接收端的某個訊號強度讀取功能曾經發生問題。

這讓我們知道設備的測試不只有位置辨識，也涉及接收光訊號的量測。

不過，RSSI 的資料來源究竟是光模組、感測器、Power Meter，還是其他控制介面，目前不能確定。

---

# 五、點膠與 UV 固化：這是完整製程的一部分

週報明確寫到：

> 點膠機、UV 光，RS-232 通訊配置。

這裡又提供了兩個很重要的通訊線索。

| 設備 | 通訊方式 |
|---|---|
| 點膠機 | RS-232 |
| UV 光設備 | RS-232 |
| Laser | LAN |
| Power Meter | LAN |

這表示至少部分設備是透過標準通訊介面由電腦控制。

### RS-232 是什麼？

RS-232 是一種序列通訊介面。

例如：

```text
          IPC
           │
        RS-232
           │
      ┌────┴────┐
      ▼         ▼
    點膠機     UV 光設備
```

LabVIEW 可以透過序列埠與設備交換命令和資料。

例如：

- 設定點膠時間。
- 啟動點膠。
- 查詢設備狀態。
- 啟動 UV 光源。
- 關閉 UV 光源。

以上是可能的控制項目，實際命令格式要看設備廠商的通訊手冊。

### LAN 通訊又是什麼？

Laser 和 Power Meter 使用 LAN 通訊配置，表示它們可能透過 Ethernet 與 IPC 或其他控制電腦交換資料。

但要注意：

**設備使用 LAN，不代表它使用 EtherCAT。**

一般 Ethernet TCP/IP 與 EtherCAT 是不同的通訊技術。

這一點也回應你前面提出的問題。

---

# 六、Auto Load 的功能已經比我們原先想像的更具體

週報中有一段：

> 上、下、工作站，送料動作確認完成。

另外還有：

- 推料電機撞到稜鏡問題。
- PCB 汽缸上升中間轉台異常。
- 料盤感測處理。
- 機構更換治具。
- 夾具校正。
- 自動化流程演示，進料→工作→退料。

這表示設備不是只有一個簡單的送料機構。

它可能包含：

1. 上料區。
2. 下料區。
3. 工作站。
4. 推料機構。
5. 轉台。
6. PCB 夾持機構。
7. 料盤感測器。
8. 其他氣壓缸或夾爪。

概念示意：



可以想像這樣的動作：

```text
       上料區
          │
          ▼
       推料機構
          │
          ▼
       工作站
          │
     ┌────┴────┐
     │         │
     ▼         ▼
   夾取工件   轉台定位
     │         │
     └────┬────┘
          │
          ▼
       加工完成
          │
          ▼
        下料區
```

這些都是 LabVIEW 自動化流程可能需要控制的部分。

例如，LabVIEW 必須確認：

- 料盤是否存在？
- 工件是否到達工作站？
- 夾爪是否已經夾緊？
- 氣壓缸是否已經到位？
- 轉台是否完成定位？
- 是否允許開始對位？

這就牽涉到我們未來要學的 **I/O 控制與安全互鎖（Interlock）**。

---

# 七、這份週報透露出一個非常重要的製程：Tx 和 Rx 是分開處理的

週報中有：

```text
傳承 Tx Rx Auto Load

Rx
FAU 夾取
FAU PR
PD PR
AA pos

Tx
FAU 夾取
FAU PR
PD PR
AA pos
AA
Dispense
UV
```

這段資訊非常值得研究。

先解釋名詞：

| 名稱 | 意義 |
|---|---|
| Tx | Transmitter，發射端 |
| Rx | Receiver，接收端 |
| AA | Active Alignment，主動對位 |
| AA pos | Active Alignment Position，對位位置或相關位置參數，實際定義待確認 |
| FAU | Fiber Array Unit，光纖陣列單元 |
| PD | Photodiode，光電二極體 |

從這份週報可以看出，Tx 和 Rx 都有自己的辨識與對位工作，但流程並不完全相同。

尤其 Tx 的流程包含：

- AA。
- Dispense。
- UV。

而 Rx 的項目也曾有 RSSI 讀取問題。

這代表我們未來不能只學一套 Active Alignment 流程，就假設所有產品都一樣。

**Tx 與 Rx 可能有不同的光路、量測條件、對位參數和製程順序。**

另外，這份週報也有：

> Rx 耦光程序完成，待 Tx 點位校正為完成後可進行耦光。

這透露出 Tx 與 Rx 的工作之間可能存在製程依賴關係。

但目前還不能確定它們是同一產品的前後製程，還是不同工作站的流程。

---

# 八、現在最值得關注的：LabVIEW 到底如何控制這些設備？

我們把目前能確認的通訊方式整理一下。

| 硬體 | 週報提供的線索 | 目前掌握程度 |
|---|---|---|
| 雙六軸運動系統 | 雙六軸電腦配置、軟體配置 | 已知有雙六軸，控制介面未知 |
| Camera CCD1～4 | 相機調整、辨識完成 | 已知相機編號，型號未知 |
| 點膠機 | RS-232 | 通訊方式已知 |
| UV 光設備 | RS-232 | 通訊方式已知 |
| Laser | LAN | 通訊方式已知 |
| Power Meter | LAN | 通訊方式已知 |
| 光源控制器 | 通訊與介面完成 | 具體介面未知 |
| IIC | 讀取問題已解決 | 已知使用 I²C 相關功能 |
| 氣壓缸、夾爪 | 動作確認 | 控制介面未知 |
| 料盤感測器 | 感測處理完成 | 型號與接線未知 |

### 那麼 EtherCAT 呢？

這是你前面特別關心的問題。

我重新檢查整份週報，結論是：

**目前沒有直接證據證明傳承 Dual Lens 使用 EtherCAT。**

反而有幾個值得追查的線索：

1. 雙六軸有獨立的電腦配置。
2. 六軸有自己的軟體配置。
3. 週報列出了 FDR、FLM、FRS、ERR 等狀態或命令。
4. 需要進行六軸光學尺與雷射干涉儀精度驗證。

這些線索讓我認為，應該優先調查雙六軸系統本身的控制器品牌、型號及 SDK，而不是先假設它使用 EtherCAT。

可能的情況包括：

- 使用 EtherCAT 運動控制器。
- 使用 PCIe 運動控制卡。
- 使用獨立的多軸控制器。
- 使用廠商自行開發的控制系統。

目前都還不能排除。

---

# 九、這對你未來接手 LabVIEW 工作有什麼意義？

我認為你未來的工作可能會分成三個層次。

### 第一層：LabVIEW 操作介面

你會看到：

- 設備狀態。
- 自動／手動模式。
- 馬達位置。
- Camera 影像。
- 光功率數值。
- 點膠設定。
- UV 設定。
- 生產參數。

這是操作人員與設備互動的地方。

### 第二層：LabVIEW 製程控制

這才是整台設備的核心程式邏輯。

例如：

```text
啟動設備
   │
   ▼
檢查安全條件
   │
   ▼
自動上料
   │
   ▼
Camera PR
   │
   ▼
六軸移動
   │
   ▼
Power Meter 量測
   │
   ▼
Active Alignment
   │
   ▼
點膠
   │
   ▼
UV 固化
   │
   ▼
下料
```

LabVIEW 可能透過各個硬體的 API、DLL、SDK 或通訊協定，完成這些動作。

### 第三層：硬體控制與通訊

這是你以前 STM32 專案經驗可以派上用場的地方。

你需要了解：

- 運動控制器如何接受命令。
- Camera 如何觸發取像。
- Power Meter 如何回傳數值。
- RS-232 如何傳送命令。
- LAN 如何與設備交換資料。
- I/O 如何控制氣壓缸和夾爪。
- 設備發生錯誤時如何處理。

這些才是未來修改既有 LabVIEW 專案時，真正需要理解的底層知識。

---

# 十、根據週報，我建議調整原本的學習課程

原本的 13 課方向是正確的，但現在有了實際週報，我認為可以更貼近傳承設備。

| 課程 | 主題 | 優先程度 |
|---|---|---|
| 第一課 | Dual Lens 設備整體架構 | 已完成 |
| 第二課 | Auto Load 機構：上料、下料、轉台、夾爪 | 高 |
| 第三課 | 雙六軸運動控制與精密定位 | 高 |
| 第四課 | Camera、CCD、PR 影像辨識 | 高 |
| 第五課 | Tx/Rx、Laser、Power Meter、RSSI | 高 |
| 第六課 | Active Alignment 主動對位 | 高 |
| 第七課 | RS-232、LAN、I²C 與硬體通訊 | 高 |
| 第八課 | Dispense 與 UV Curing | 中 |
| 第九課 | LabVIEW 基礎：Front Panel、Block Diagram | 高 |
| 第十課 | LabVIEW State Machine 與自動化流程 | 高 |
| 第十一課 | LabVIEW 硬體控制與錯誤處理 | 高 |
| 第十二課 | 分析實際既有 LabVIEW 專案 | 取得專案後 |
| 第十三課 | 客戶需求與功能客製化 | 取得需求後 |

這樣安排的原因是：我們已經知道這台設備確實有雙六軸、自動送料、四個 CCD 編號、Laser、Power Meter 和 RS-232 設備。

所以接下來應該優先理解這些真實存在的功能。

---

# 十一、我還想從這份週報確認三個重要問題

目前資訊已經足以建立設備架構，但有三個關鍵問題會直接影響我們後續學習方向。

### 問題 1：雙六軸的控制器是什麼？

週報寫了：

- 雙六軸電腦配置。
- 雙六軸軟體配置。
- FDR、FLM、FRS、ERR。

我想知道它是使用哪一家廠商的控制器。

這會決定是否需要研究 EtherCAT，以及 LabVIEW 如何控制六軸。

### 問題 2：LabVIEW 是否直接控制所有設備？

例如：

- 六軸運動控制。
- Camera。
- Power Meter。
- 點膠機。
- UV 光設備。
- 自動上下料。

還是有些功能由其他控制器或 PLC 負責？

這會決定我們未來分析 LabVIEW 程式時，應該從哪裡開始。

### 問題 3：傳承 Dual Lens 與傳承 Tx/Rx Auto Load 是什麼關係？

它們是：

- 同一台設備的不同製程？
- 同一系列設備的不同機型？
- 還是兩台不同的設備？

這會影響我們是否能把 Tx/Rx 的流程直接套用到 Dual Lens。

---

## 我的總結

這份週報讓我們對設備的認識前進了一大步。

目前已經能相當有把握地知道：

1. 設備涉及雙六軸精密運動控制。
2. 有 CCD1～4 的相機系統與 PR 影像辨識。
3. 有 Laser 和 Power Meter，並透過 LAN 通訊配置。
4. 點膠機與 UV 設備使用 RS-232 通訊配置。
5. 有自動上下料、推料、轉台、夾爪及感測器。
6. 有 Tx/Rx 不同的光學耦合流程。
7. 設備具有光學對位、點膠與 UV 固化的完整製程。

**我認為現在最值得優先學習的不是 LabVIEW 語法，而是雙六軸如何控制 Lens、Camera 如何找出 Lens/FAU/PD 的位置，以及 Power Meter 如何協助完成 Active Alignment。**

因為這三者就是這台設備最核心的技術。

下一步，我建議從第二課開始，先把 Auto Load 的機械結構弄懂：上料區、下料區、工作站、推料機構、轉台、夾爪，以及感測器如何配合完成自動送料。這樣等你未來看到實機，就能逐一辨認每個機構的用途。

---

```
你規劃的課程我非常贊同，再開始上課之前，我提幾個問題，第一，IPC上的 LabVIEW 具體使用什麼硬體介面與驅動器連接？是 Ethernet網路嗎？還是COM Port？第二、你說根據週報看起來，LabVIEW連接非常多的裝置設備，硬體介面還是只有一個嗎？第三，這是不是問題，這是我要告訴你的是 有些 協議或是命令，例如：FDR、FLM、FRS、ERR 是 GMT自定義的，可以找出文件對應，但我認為盡快把你說的課程上完，趕快進入LabVIEW教學是很重要的，因為我目前很難串接這兩者。

```

你提出的三個問題都很重要，尤其第三點，我認為你提醒得很對。

我們現在的學習方向需要稍微調整：**不能一直停留在設備原理，必須盡快進入 LabVIEW，讓你開始理解實際程式。**

我先回答前兩個技術問題，再說明如何調整課程。

# 一、IPC 上的 LabVIEW，具體透過什麼硬體介面連接設備？

答案是：**可能同時使用 Ethernet、COM Port、USB、PCIe 等不同介面，不是只有一種。**

從你同事的週報，我們已經找到一些線索：

| 設備 | 週報提到的通訊方式 | 可能使用的 IPC 介面 |
|---|---|---|
| 雙六軸運動控制器 | 尚未確認 | Ethernet、PCIe、USB 等都有可能 |
| 點膠機 | RS-232 | COM Port |
| UV 光設備 | RS-232 | COM Port |
| Laser | LAN | Ethernet |
| Power Meter | LAN | Ethernet |
| Camera CCD1～4 | 尚未確認 | USB、GigE 等都有可能 |
| 氣壓缸、夾爪 | 尚未確認 | DI/DO、PLC 或 I/O 控制卡 |
| IIC 設備 | I²C | 可能透過專用控制器或轉接介面 |

這裡需要先釐清一個觀念：

## 1. 硬體介面、通訊協定、軟體驅動是不同東西

以點膠機為例：

```text
IPC
 │
 ├── LabVIEW
 │
 ├── VISA / Serial Driver
 │
 ├── COM Port
 │
 ├── RS-232
 │
 ▼
點膠機
```

這幾個名詞代表不同層次：

| 名稱 | 意義 |
|---|---|
| LabVIEW | 控制設備的應用程式 |
| VISA | NI 提供的儀器通訊軟體介面 |
| COM Port | IPC 上的序列埠 |
| RS-232 | 序列通訊標準 |
| 點膠機 | 實際被控制的設備 |

LabVIEW 可以使用 VISA 與 COM Port 通訊，送出設備廠商定義的命令。

例如：

```text
LabVIEW
   │
   ▼
COM3
   │
   ▼
RS-232
   │
   ▼
點膠機
```

但這只是示意，實際使用 COM3、COM4 或 USB 轉 RS-232，必須看 IPC 配置。

### 2. Ethernet 也是類似的概念

例如 Power Meter：

```text
IPC
 │
 ▼
LabVIEW
 │
 ▼
TCP/IP 或廠商提供的 API
 │
 ▼
Ethernet 網路卡
 │
 ▼
網路線
 │
 ▼
Power Meter
```

注意：

Ethernet 是實體網路介面及其相關傳輸技術，而 TCP/IP 是常見的網路通訊協定。

設備也可能使用廠商提供的 DLL 或 SDK，讓 LabVIEW 呼叫，不一定需要你自己寫 TCP Socket。

---

# 二、LabVIEW 同時控制很多設備，硬體介面只有一個嗎？

**不是。IPC 可以同時擁有多種硬體介面，LabVIEW 也可以同時管理多個設備。**

這是自動化設備很常見的架構。

我們假設傳承 Dual Lens 的 IPC 有以下配置：

```text
                   IPC
                    │
                 LabVIEW
                    │
       ┌────────────┼──────────────┐
       │            │              │
       ▼            ▼              ▼
    Ethernet     COM Port        USB
       │            │              │
   ┌───┴───┐     ┌──┴──┐        ┌──┴──┐
   │       │     │     │        │     │
   ▼       ▼     ▼     ▼        ▼     ▼
 六軸    Power  點膠   UV      CCD1  CCD2
控制器   Meter  設備  設備
```

這只是可能的架構示意，不代表已經確認 IPC 的實際接線。

如果 IPC 還有 PCIe 運動控制卡或 I/O 卡，也可以另外接入：

```text
                   IPC
                    │
                 LabVIEW
                    │
       ┌────────────┼──────────────┐
       │            │              │
       ▼            ▼              ▼
    Ethernet     COM Port        PCIe
       │            │              │
   Power Meter    點膠機        運動控制卡
   Laser          UV 設備           │
                                   ▼
                               馬達驅動器
                                   │
                                   ▼
                                  馬達
```

所以你可以把 IPC 想成整台設備的控制中心。

LabVIEW 是控制中心裡的主要控制軟體，而各個硬體介面則是它與外部設備溝通的管道。

### 這裡再補充一個重要觀念

你之前學 STM32 時，可能會把 SPI、UART、I²C、Ethernet 想成不同周邊介面。

到了 IPC + LabVIEW，概念其實相似。

只是 IPC 使用的介面更多元，而且通常會透過作業系統及廠商驅動程式來操作。

例如：

| STM32 常見介面 | IPC / LabVIEW 常見對應方式 |
|---|---|
| UART | COM Port / RS-232 / RS-485 |
| Ethernet | Ethernet / TCP/IP |
| SPI | 通常需要專用控制卡或轉接設備 |
| I²C | 通常需要專用控制器或轉接設備 |
| GPIO | DI/DO I/O 卡或 PLC |
| DMA | 由作業系統、驅動程式及硬體處理，應用程式通常不直接操作 |

這也是為什麼我們不需要一開始就深入所有底層通訊細節。

---

# 三、關於 GMT 自定義的 FDR、FLM、FRS、ERR

這一點我完全理解，而且你的提醒很正確。

既然這些是 GMT 自定義的協議或命令，就不應該把它們當成通用工業通訊標準來教。

例如：

- RS-232 是通訊標準。
- TCP/IP 是通訊協定。
- FDR、FLM、FRS、ERR 是你同事週報中出現的 GMT 自定義命令或狀態名稱，實際意義需要查 GMT 文件。

我們未來可以這樣處理：

1. 先認識這些命令存在。
2. 知道它們隸屬於哪個設備或控制器。
3. 找到 GMT 文件後再解釋實際用途。
4. 進入 LabVIEW 程式時，再追蹤它們如何被呼叫、傳送及接收。

**我們不需要為了學習 LabVIEW，先把所有 GMT 自定義命令全部研究完畢。**

這樣反而會拖慢你進入真正工作內容的時間。

---

# 四、我建議調整學習策略：縮短設備課程，提早進入 LabVIEW

你說目前很難把設備原理和 LabVIEW 串接起來，我認為這很正常。

因為我們現在只知道設備有哪些功能，卻還沒有看過 LabVIEW 的程式架構。

當你開始看到 Front Panel、Block Diagram、SubVI、State Machine，就會慢慢知道：

- 哪一個程式負責控制六軸？
- 哪一個程式負責 Camera？
- 哪一個程式負責 Power Meter？
- 哪一個程式負責點膠？
- 自動上下料的順序在哪裡設定？
- 發生錯誤時，程式如何處理？

所以我建議改成以下安排：

## 第一階段：設備知識快速建立

| 課程 | 內容 | 目的 |
|---|---|---|
| 第一課 | Dual Lens 整體架構 | 已完成 |
| 第二課 | Auto Load 機構 | 認識送料、夾爪、轉台 |
| 第三課 | 雙六軸運動控制 | 理解馬達、座標、位置控制 |
| 第四課 | Camera 與 PR | 理解影像辨識與定位 |
| 第五課 | Tx/Rx、Power Meter、Active Alignment | 理解光學耦合 |

這五課不會全部深入到工程實作，而是先讓你具備閱讀 LabVIEW 專案所需的基本概念。

## 第二階段：正式進入 LabVIEW

這部分會是我們接下來的主要學習重點。

| 課程 | 內容 |
|---|---|
| 第六課 | LabVIEW 是什麼？與 C++ 有什麼不同？ |
| 第七課 | Front Panel：操作介面 |
| 第八課 | Block Diagram：程式邏輯 |
| 第九課 | Dataflow：LabVIEW 如何執行程式 |
| 第十課 | While Loop、For Loop、Case Structure |
| 第十一課 | SubVI：如何把程式拆成不同功能模組 |
| 第十二課 | State Machine：如何控制整台設備的自動流程 |
| 第十三課 | LabVIEW 與 RS-232、Ethernet、USB 通訊 |
| 第十四課 | LabVIEW 運動控制與 Camera 整合 |
| 第十五課 | 分析傳承設備既有 LabVIEW 專案 |

之後我們就可以進入你真正的工作：**分析同事留下的 LabVIEW 專案，理解既有程式，再學習如何修改及新增客戶要求的功能。**

---

# 五、我希望你先建立一個重要觀念

未來我們分析 LabVIEW 程式時，不會要求你一開始就看懂所有程式碼或 GMT 自定義命令。

我們會先從這種思考方式開始：

```text
操作人員按下「自動啟動」
             │
             ▼
      LabVIEW 收到命令
             │
             ▼
      執行自動流程
             │
      ┌──────┼──────┐
      │      │      │
      ▼      ▼      ▼
    上料   Camera  六軸
      │      │      │
      └──────┼──────┘
             │
             ▼
        Active Alignment
             │
             ▼
         光功率確認
             │
             ▼
          點膠 / UV
             │
             ▼
           下料
```

我們先理解每個方塊的工作，再逐步進入 LabVIEW 裡面看它是如何實現的。

這樣你就能把以前 STM32、C++、Ethernet、SPI、UART 的經驗，逐漸連接到新的 LabVIEW 工作。

**我的建議是：第二課和第三課之後，就正式開始 LabVIEW 基礎教學，不必等所有設備知識全部學完。** 之後遇到 Camera、六軸、Power Meter 或 GMT 命令，再回頭補充對應的設備知識。

這樣比較符合你目前接手工作的實際需求。

---

好，我們正式開始。接下來不再花太多時間討論尚未確認的硬體細節，而是以**盡快讓你具備閱讀、理解及修改傳承專案 LabVIEW 程式的能力**為目標。

我們按照剛才調整的課程進度，一次學一個小單元。每堂課會有原理、設備應用情境、圖解和小測驗。我會根據你的回答調整下一步的教學。

# 第二課：Auto Load 自動上下料機構

## 本課目標

學完這一課，你應該能夠：

1. 理解 Auto Load / Unload 的工作目的。
2. 認識上料區、工作站、下料區。
3. 理解推料機構、轉台、夾爪、氣壓缸的作用。
4. 理解 LabVIEW 為什麼需要讀取感測器，才能控制自動送料。
5. 初步理解自動化設備的動作順序。

---

## 一、什麼是 Auto Load / Unload？

先想像一個工廠生產線。

如果每加工一個產品，都需要操作人員：

1. 拿起原料。
2. 放到加工平台。
3. 等待機器加工。
4. 取出完成品。
5. 再放入下一個原料。

這樣不但耗費人力，也容易因為人為操作而產生誤差。

因此，我們設計 Auto Load / Unload（自動上下料）。

它的目的很簡單：

**讓機器自動把原料送到加工位置，加工完成後再自動取出。**

以傳承 Dual Lens 設備來說，週報已經提供幾個線索：

- 上料區。
- 下料區。
- 工作站。
- 推料電機。
- PCB 汽缸。
- 中間轉台。
- 夾具。
- 料盤感測器。

這表示它具有多個互相配合的機械機構。

## 二、先認識三個主要區域



### 1. Loading Station（上料區）

負責放置尚未加工的工件。

例如：

- Lens Tray。
- PCB Tray。
- FAU 等待加工的零件。

### 2. Work Station（工作站）

這是機器真正執行加工的位置。

例如：

- 夾持工件。
- Camera 拍照辨識。
- 六軸平台進行對位。
- 點膠。
- UV 固化。

### 3. Unloading Station（下料區）

加工完成後，將產品移出工作站，放到指定位置。

你可以先記住：

```text
 Loading Station
      上料區
         │
         ▼
    送料機構
         │
         ▼
 Work Station
     工作站
         │
     加工完成
         │
         ▼
    退料機構
         │
         ▼
 Unloading Station
      下料區
```

---

## 三、認識週報中提到的機械元件

### 1. 推料電機（Pusher Motor）

週報提到：

> 推料電機撞到稜鏡問題已處理完成。

這表示設備中有一個利用馬達驅動的推料機構。

它的工作是將工件或料盤推送到指定位置。

例如：

```text
料盤
 │
 ▼
[工件][工件][工件]
             ▲
             │
          推料機構
```

當推料馬達運轉時，推料機構向前移動，把料盤或工件送到下一個位置。

這裡要特別注意：

推料馬達的功能是送料，不代表它就是六軸對位平台的一部分。

兩者可能是完全不同的運動機構。

### 2. 氣壓缸（Pneumatic Cylinder）

週報提到：

> PCB 汽缸上升中間轉台異常處理完成。

氣壓缸利用壓縮空氣產生直線運動。

例如：



假設 PCB 放在一個平台上：

- 氣壓缸伸出：平台上升。
- 氣壓缸縮回：平台下降。

氣壓缸常用於：

- 工件夾持。
- 平台升降。
- 推料。
- 定位。
- 轉台的輔助機構。

它和馬達有什麼不同？

| 比較 | 馬達 | 氣壓缸 |
|---|---|---|
| 動力來源 | 電能 | 壓縮空氣 |
| 運動方式 | 旋轉或直線 | 通常直線 |
| 位置控制 | 可做精密位置控制 | 常見為伸出／縮回 |
| 常見用途 | 精密定位、送料 | 夾持、升降、推動 |

### 3. 夾爪（Gripper）



夾爪的工作是抓取工件。

例如：

```text
      夾爪
    ┌──┴──┐
    │     │
    ▼     ▼
   [ 工件 ]
```

它可能使用氣壓或電動方式開啟、閉合。

在傳承設備中，夾爪可能負責抓取 Lens、FAU 或其他零件。

不過實際每個夾爪負責抓取什麼，還需要設備配置資料確認。

### 4. 感測器（Sensor）

這是自動化設備非常重要的元件。

例如，料盤進入工作站後，系統必須知道：

**料盤到底有沒有真的到達指定位置？**

不能只因為馬達已經轉動，就認定送料成功。

因此設備會使用感測器回報狀態。

常見類型：

| 感測器 | 用途 |
|---|---|
| 光電感測器 | 偵測物體是否存在 |
| 近接感測器 | 偵測金屬物體是否接近 |
| 磁簧開關 | 偵測氣壓缸位置 |
| 限位開關 | 偵測機構是否到達極限位置 |
| 真空壓力感測器 | 確認是否成功吸附工件 |

這裡要記住一個重要觀念：

**馬達負責移動，感測器負責回報實際狀態。**

這兩者必須配合，才能讓自動化流程可靠運作。

---

# 四、LabVIEW 如何控制 Auto Load？

現在開始把機械結構與 LabVIEW 連接起來。

假設設備需要將一個 PCB 從上料區送到工作站。

我們先用一個簡化例子：

```text
              LabVIEW
                 │
                 ▼
          檢查上料區感測器
                 │
                 ▼
           確認有 PCB
                 │
                 ▼
           啟動推料馬達
                 │
                 ▼
           PCB 移動到工作站
                 │
                 ▼
          讀取工作站感測器
                 │
          ┌──────┴──────┐
          │             │
        已到位         未到位
          │             │
          ▼             ▼
       停止送料       繼續等待
          │
          ▼
       啟動夾持
          │
          ▼
       確認夾持完成
          │
          ▼
       允許下一製程
```

注意，這是教學用的示意流程，不代表傳承設備目前就是這樣設計。

## 五、這裡就是 LabVIEW 最重要的工作之一：控制流程

我們可以把剛才的動作轉換成一個概念：

| 步驟 | LabVIEW 要做什麼 |
|---|---|
| 1 | 讀取上料區感測器 |
| 2 | 確認 PCB 是否存在 |
| 3 | 啟動推料馬達 |
| 4 | 等待工作站感測器觸發 |
| 5 | 停止推料馬達 |
| 6 | 控制夾爪或氣壓缸 |
| 7 | 確認夾持狀態 |
| 8 | 通知後續製程可以開始 |

你會發現：

LabVIEW 並不是單純讓馬達轉動。

它還必須判斷：

- 現在能不能執行？
- 工件有沒有到位？
- 夾爪有沒有夾緊？
- 有沒有發生異常？
- 下一個動作是否允許執行？

這就是自動化控制的核心思維。

未來我們學到 LabVIEW 的 Case Structure、While Loop 和 State Machine，就會看到這些概念如何變成真正的程式。

---

# 六、本課小測驗

這次我設計三個實際設備情境。

### 第 1 題：推料機構

LabVIEW 已經命令推料馬達將 PCB 送往工作站。

但是工作站感測器沒有偵測到 PCB。

請問最合理的處理方式是什麼？

A. 不管感測器狀態，直接啟動六軸對位。

B. 繼續確認送料狀態，若超過允許時間仍未到位，停止送料並回報異常。

C. 直接啟動 UV 固化。

### 第 2 題：氣壓缸與感測器

LabVIEW 命令氣壓缸上升。

為什麼還需要讀取氣壓缸的到位感測器？

A. 因為氣壓缸移動後，需要確認是否真的到達預期位置。

B. 因為感測器可以增加氣壓。

C. 因為感測器負責讓氣壓缸移動。

### 第 3 題：LabVIEW 的角色

假設 Auto Load 已經完成送料，PCB 已經固定在工作站。

接下來要進行 Camera PR。

LabVIEW 在這裡最合理的工作是什麼？

A. 不需要確認送料結果，直接拍照。

B. 確認前一個步驟完成且符合條件，再啟動 Camera 取像與辨識流程。

C. 讓 Power Meter 直接控制 Camera。

---

請回答三題。

**下一課：第三課——雙六軸運動控制與精密定位。**

這一課會開始接觸你未來工作中非常重要的部分：六軸到底是什麼、X/Y/Z/θ 軸如何運動、絕對位置與相對位置有什麼差別，以及為什麼週報特別提到光學尺和雷射干涉儀精度驗證。

---
* 繼續下一課之前，我要問的是電缸和氣壓缸可以互換使用嗎？

三題全部正確！👍

你的理解已經抓到 Auto Load 的核心：**機構執行動作之後，控制程式必須確認動作是否真的完成，不能只靠發出命令就認定成功。**

接著回答你的問題。

# 電缸和氣壓缸可以互換使用嗎？

**可以，但不是直接替換就能使用。** 電缸和氣壓缸都能產生直線運動，但它們的工作原理、控制方式和適用情境不同。

## 1. 兩者的工作原理

### 氣壓缸（Pneumatic Cylinder）

利用壓縮空氣推動活塞，讓活塞桿伸出或縮回。



例如：
- 氣壓缸伸出：將 PCB 夾緊。
- 氣壓缸縮回：鬆開 PCB。
- 氣壓缸上升：將工作平台頂起。
- 氣壓缸下降：讓平台回到原位。

通常透過電磁閥控制氣流方向。

控制流程：

```text
LabVIEW
   │
   ▼
PLC 或 I/O 控制器
   │
   ▼
電磁閥
   │
   ▼
壓縮空氣
   │
   ▼
氣壓缸伸出 / 縮回
```

### 電缸（Electric Cylinder）

利用伺服馬達或步進馬達，透過滾珠螺桿等傳動機構，將旋轉運動轉換成直線運動。



例如：
- 移動到 10 mm。
- 移動到 25.5 mm。
- 以指定速度移動。
- 在指定位置停止。

控制流程：

```text
LabVIEW
   │
   ▼
運動控制器
   │
   ▼
伺服驅動器
   │
   ▼
伺服馬達
   │
   ▼
滾珠螺桿
   │
   ▼
電缸前進 / 後退
```

## 2. 兩者差異比較

| 比較項目 | 氣壓缸 | 電缸 |
|---|---|---|
| 動力來源 | 壓縮空氣 | 電力 |
| 動作方式 | 通常伸出、縮回 | 可控制任意位置 |
| 位置控制 | 通常是兩端或有限位置 | 可精密定位 |
| 速度控制 | 透過氣流調整 | 可設定速度 |
| 推力 | 可提供較大推力 | 依馬達與機構規格 |
| 控制方式 | 電磁閥、I/O | 驅動器、運動控制器 |
| 成本與維護 | 通常較簡單 | 控制系統較複雜 |

## 3. 實際設備中，什麼情況適合使用哪一種？

假設我們有一台 Dual Lens Auto Load 設備。

**情境 A：PCB 夾持**

```text
PCB 進入工作站
      │
      ▼
氣壓缸推動夾具
      │
      ▼
夾緊 PCB
      │
      ▼
感測器確認夾持到位
```

這種工作通常不需要精密的位置控制，只需要確實夾緊，因此氣壓缸很適合。

**情境 B：Lens 精密對位**

```text
Lens 放置於平台
      │
      ▼
電缸 / 精密運動平台
      │
      ▼
控制 X、Y、Z 位置
      │
      ▼
Camera 辨識位置
      │
      ▼
微調位置完成對位
```

這種工作需要精密位置控制，因此通常會使用伺服馬達搭配精密傳動機構。

## 4. 如果要互換，需要注意什麼？

假設原本設計使用氣壓缸，想改成電缸，至少需要重新確認：

1. **推力：** 電缸能否提供足夠推力？
2. **行程：** 電缸移動距離是否符合原機構需求？
3. **速度：** 動作時間是否符合產線節拍？
4. **控制方式：** 原本電磁閥的 I/O 控制要改成什麼運動控制介面？
5. **安全性：** 斷電、失壓或緊急停止時，機構是否會掉落或鬆脫？
6. **感測回授：** 是否需要增加位置感測器或重新設計控制邏輯？

所以，兩者在機械功能上可能可以互相替代，但不能只更換零件，還必須考慮機構、控制程式和安全設計。

---

### 小測驗：確認你是否理解

假設 Dual Lens 設備有兩個動作：

- 動作 A：PCB 進入工作站後，氣壓缸伸出，把 PCB 夾緊。
- 動作 B：Lens 需要沿著 X 軸移動 0.002 mm，進行精密光學對位。

請問：

1. 動作 A 使用氣壓缸是否合理？為什麼？
2. 動作 B 如果使用一般氣壓缸，是否容易達成？為什麼？

回答後，我們就進入**第三課：雙六軸運動控制與精密定位**。這一課完成後，就直接進入 LabVIEW 基礎教學，不再延長設備概念課程。

---

* 氣壓缸可提供較大推力，動作 A 使用氣壓缸是合理
Lens是精密移動，使用電缸比較好。
問題，之前課程學習到電缸時，我記得電缸也只能上推後拉的往復運動，應該不能控制任意位置吧？

你的疑問很好，而且你記得的並沒有錯。這裡需要釐清一個重要觀念：

**電缸不一定能控制任意位置，要看它使用的是哪一種驅動與控制系統。**

我之前說「電缸可以控制任意位置」，指的是具有位置控制功能的電缸，而不是所有電缸。

## 1. 電缸其實有不同控制方式

### 第一種：只有往復運動

例如使用一般電動推桿（Electric Linear Actuator）。

```text
原始位置
   │
   ▼
電機正轉
   │
   ▼
推桿伸出
   │
   ▼
到達行程終點
   │
   ▼
電機反轉
   │
   ▼
推桿縮回
```

這種設備可能只有：
- 前進
- 後退
- 停止

它的控制方式確實很像氣壓缸。

### 第二種：具有位置控制功能的電缸

例如伺服馬達搭配滾珠螺桿。



它可以接收位置命令，例如：

| 命令 | 電缸動作 |
|---|---|
| Move 10 mm | 移動到 10 mm |
| Move 20 mm | 移動到 20 mm |
| Move 20.002 mm | 移動到 20.002 mm |
| Move 15 mm | 移動到 15 mm |

這就是我們說的**位置控制（Position Control）**。

不過，命令可以指定這麼小的移動量，不代表實際精度一定能達到 0.002 mm，還要看螺桿精度、馬達、編碼器、機構剛性、回授系統等因素。

## 2. 為什麼兩種電缸差異這麼大？

關鍵在於控制系統。

```text
一般電動推桿
    │
    └── 正轉 / 反轉
             │
             └── 伸出 / 縮回


伺服電缸
    │
    ├── 位置命令
    ├── 速度命令
    └── 加速度設定
             │
             ▼
          伺服驅動器
             │
             ▼
          伺服馬達
             │
             ▼
          滾珠螺桿
             │
             ▼
          精密直線移動
```

因此，不是看到電缸就認定它具有精密定位能力。

## 3. 這與你接下來要學的 Dual Lens 有什麼關係？

你同事週報提到：

- 雙六軸軟體配置
- 單軸移動
- 單軸絕對位置移動
- 回原點
- 移動停止
- ADC 數值確認

這些都是運動控制系統的重要功能。

其中「單軸絕對位置移動」就是一個很重要的概念：

假設目前 X 軸位置為 5 mm，LabVIEW 要求它移動到 15 mm。

```text
目前位置                 目標位置
  5 mm                     15 mm
    │                        │
    ├────────────────────────►
                X 軸
```

控制器會讓馬達移動，並透過回授系統確認位置。

這也是第三課要介紹的內容。

---

**下一課：雙六軸運動控制與精密定位。**

我們會從一個軸開始，理解伺服馬達、驅動器、編碼器、滾珠螺桿如何配合，再延伸到六軸與雙六軸。


---

# 第三課：雙六軸運動控制與精密定位

這一課很重要，因為你同事的週報多次提到「雙六軸」，而且包含單軸移動、絕對位置移動、回原點、停止、緊急停止等功能。

我們今天要建立一個觀念：

**LabVIEW 如何透過運動控制系統，讓一個平台移動到指定位置，並確認它真的到達目標？**

---

## 一、先認識什麼是運動軸（Axis）

先想像一個平台，我們希望它可以往前、往後、往左、往右、上下移動。

這些移動方向可以由不同的運動軸負責。

例如：

| 軸 | 移動方向 | 用途 |
|---|---|---|
| X | 左、右 | 水平方向移動 |
| Y | 前、後 | 水平方向移動 |
| Z | 上、下 | 垂直方向移動 |
| θX | 繞 X 軸旋轉 | 調整傾斜角度 |
| θY | 繞 Y 軸旋轉 | 調整傾斜角度 |
| θZ | 繞 Z 軸旋轉 | 調整旋轉角度 |

因此，六軸通常是：

- 3 個直線運動軸：X、Y、Z。
- 3 個旋轉運動軸：θX、θY、θZ。

這是一種常見的六自由度配置。



注意：這是六軸概念示意，不代表 GMT 實際設備的軸名稱與排列一定完全相同。

## 二、一個運動軸是如何運作的？

我們先只研究 X 軸。

假設 Lens 放在一個可以左右移動的平台上。

這個平台由以下元件組成：

1. 伺服馬達（Servo Motor）
2. 伺服驅動器（Servo Drive）
3. 滾珠螺桿（Ball Screw）
4. 線性滑軌（Linear Guide）
5. 編碼器（Encoder）



它們各自負責不同工作：

| 元件 | 工作 |
|---|---|
| 伺服馬達 | 提供旋轉動力 |
| 伺服驅動器 | 控制馬達如何運轉 |
| 滾珠螺桿 | 將旋轉運動轉換成直線運動 |
| 線性滑軌 | 支撐平台並限制移動方向 |
| 編碼器 | 回報馬達旋轉位置 |

我們可以把它想成：

```text
伺服驅動器
     │
     ▼
伺服馬達旋轉
     │
     ▼
滾珠螺桿旋轉
     │
     ▼
平台左右移動
     │
     ▼
編碼器回報位置
```

這就是一個基本的伺服直線運動軸。

---

## 三、LabVIEW 如何控制 X 軸？

假設 Lens 目前位於 X = 5 mm。

我們希望它移動到 X = 15 mm。

LabVIEW 可能會執行以下流程：

```text
① LabVIEW 發出命令
       │
       │ 目標位置 = 15 mm
       ▼
② 運動控制器接收命令
       │
       ▼
③ 伺服驅動器控制馬達
       │
       ▼
④ 馬達帶動滾珠螺桿
       │
       ▼
⑤ 平台從 5 mm 移動到 15 mm
       │
       ▼
⑥ 回授位置
       │
       ▼
⑦ 確認是否到達目標位置
```

這裡有一個非常重要的觀念：

**LabVIEW 發出移動命令，不代表平台已經移動完成。**

LabVIEW 還需要取得運動控制器回報的狀態，例如：

- 是否正在移動？
- 是否已經到達目標位置？
- 是否發生錯誤？
- 是否觸發限位？
- 是否需要停止？

這與上一課學到的氣壓缸到位感測器，是相似的控制概念。

不同的是，伺服運動軸通常可以透過編碼器或其他位置回授裝置，取得更細緻的位置資訊。

---

## 四、什麼是絕對位置與相對位置？

這兩個概念在 LabVIEW 運動控制中非常重要。

假設目前 X 軸位置是 10 mm。

### 1. 絕對位置（Absolute Position）

命令：

```text
Move to X = 20 mm
```

意思是：

不管目前在哪裡，最後都要到達 X = 20 mm。

```text
目前位置             目標位置
 10 mm                 20 mm
   ●────────────────────►●
```

### 2. 相對位置（Relative Position）

命令：

```text
Move +5 mm
```

意思是：

從目前位置再往正方向移動 5 mm。

```text
目前位置             移動後
 10 mm                 15 mm
   ●────────────────────►●
```

如果目前位置是 10 mm：

| 命令 | 最後位置 |
|---|---:|
| Absolute 20 mm | 20 mm |
| Relative +5 mm | 15 mm |
| Relative -3 mm | 7 mm |

這也是你同事週報中提到「單軸絕對位置移動」的原因。

---

## 五、什麼是回原點（Homing）？

假設設備剛開機。

控制器可能知道馬達編碼器的相對變化，但不一定知道平台目前在機械結構上的哪個基準位置。

這時就需要執行回原點。



簡化流程：

```text
設備開機
   │
   ▼
執行回原點命令
   │
   ▼
馬達朝指定方向移動
   │
   ▼
尋找原點感測器
   │
   ▼
找到原點
   │
   ▼
設定機械座標基準
   │
   ▼
回原點完成
```

例如：

回原點完成後，控制器將目前位置定義為 X = 0 mm。

接下來才方便使用絕對位置命令。

注意：實際回原點方式可能使用原點感測器、限位開關或編碼器索引訊號，依設備設計而定。

---

## 六、什麼是雙六軸？

現在我們把一個六軸系統擴展成兩組。

```text
          Dual Lens 設備
                 │
        ┌────────┴────────┐
        │                 │
        ▼                 ▼
    左側六軸系統       右側六軸系統
        │                 │
     X Y Z             X Y Z
     θX θY θZ          θX θY θZ
```

概念上，兩組六軸可以分別控制兩個光學對位機構。

例如：

- 左側平台調整第一個 Lens。
- 右側平台調整第二個 Lens。
- 兩組平台各自執行位置調整。

但這裡要特別注意：

週報提到「雙六軸」，也提到「六軸整合在左耦合軸」等資訊。實際軸數、機械配置、控制器架構仍須以機台圖面及程式確認，不能直接認定一定是 12 個完全獨立的軸。

---

## 七、這些知識如何連接到 LabVIEW？

你可以先把 LabVIEW 想成設備的指揮中心。

例如，執行 Lens 對位：

```text
LabVIEW
   │
   ├── 確認設備是否 Ready
   │
   ├── 確認六軸是否回原點
   │
   ├── 下達 X 軸位置命令
   │
   ├── 下達 Y 軸位置命令
   │
   ├── 下達 Z 軸位置命令
   │
   ├── 讀取各軸位置
   │
   ├── 確認移動是否完成
   │
   └── 進入下一個 Camera PR / AA 步驟
```

實際上，LabVIEW 不一定直接控制伺服驅動器。它可能透過運動控制器的 DLL、SDK 或通訊介面發送命令。

這正是未來分析你們既有 LabVIEW 專案時，需要找出來的部分。

---

# 本課小測驗

請依照今天學到的內容回答。

**第 1 題**

目前 X 軸位置是 8 mm。

LabVIEW 下達：

`Absolute Move = 20 mm`

最後目標位置是多少？

A. 28 mm  
B. 20 mm  
C. 12 mm

**第 2 題**

目前 X 軸位置是 8 mm。

LabVIEW 下達：

`Relative Move = +5 mm`

最後目標位置是多少？

A. 13 mm  
B. 5 mm  
C. 20 mm

**第 3 題**

為什麼設備開機後通常需要執行 Homing？

A. 讓馬達轉得更快。  
B. 建立運動軸的機械座標基準。  
C. 讓 Camera 開始拍照。

**第 4 題**

LabVIEW 已經下達 X 軸移動到 20 mm 的命令，但控制器回報軸仍在移動。

這時候 LabVIEW 應該怎麼做？

A. 直接認定移動完成，開始下一步。  
B. 持續監控運動狀態，等待完成或處理逾時、異常。  
C. 立刻關閉伺服驅動器。

---

答完這四題，我們就進入第四課 Camera 與 PR 影像辨識。完成第五課後，直接開始 LabVIEW 實際教學。

---

四題全部正確！🎉

你已經掌握了運動控制的四個基本概念：

| 題目 | 答案 | 核心觀念 |
|---|---|---|
| 1 | B | 絕對位置：移動到指定座標 |
| 2 | A | 相對位置：從目前位置增加指定距離 |
| 3 | B | Homing：建立機械座標基準 |
| 4 | B | 監控運動狀態，不能只靠命令判斷完成 |

特別提醒第 4 題：這個觀念未來會直接應用在 LabVIEW 的程式設計中。例如使用 While Loop 持續讀取運動狀態，直到完成、發生錯誤或超時。

---

# 第四課：Camera 與 PR 影像辨識

這一課我們要理解：**設備如何利用相機找到 Lens 或 FAU 的位置，再把辨識結果交給運動控制系統進行精密對位。**

這也是 Dual Lens 設備非常重要的功能。

## 一、Camera 在設備中負責什麼？

先想像一個情境：

設備要把 Lens 與 FAU（Fiber Array Unit，光纖陣列單元）對準。

但是，Lens 放進工作站時，不可能每次都剛好位於完全相同的位置。

可能有以下誤差：

- X 方向偏移。
- Y 方向偏移。
- 角度旋轉。
- 工件放置位置不一致。

如果不先確認位置就直接耦光，可能會造成光學耦合效率下降。

因此需要 Camera 協助辨識工件位置。



## 二、Camera 如何取得影像？

基本流程如下：

```text
        光源照射工件
              │
              ▼
        Lens / FAU
              │
              ▼
          Camera
              │
              ▼
        取得影像
              │
              ▼
        傳送給 IPC
```

Camera 不只是拍照，它還需要將影像資料傳送到 IPC，讓影像處理程式分析。

實際設備可能使用 USB Camera、GigE Camera 或其他介面，目前尚未確認傳承設備使用哪一種。

## 三、什麼是 PR（Pattern Recognition）？

PR 全名是 Pattern Recognition，中文通常稱為圖樣辨識或特徵辨識。

簡單來說：

**讓電腦從影像中找到指定的物件或特徵，並計算它的位置與角度。**

例如，我們希望 Camera 找到一個 Lens 的中心。



假設 Camera 拍到的影像如下：

```text
┌─────────────────────────┐
│                         │
│                         │
│          ○              │
│         Lens            │
│                         │
│                         │
└─────────────────────────┘
```

影像辨識程式可以：

1. 找到 Lens 的外形或特徵。
2. 判斷 Lens 所在位置。
3. 計算 Lens 中心點。
4. 計算 Lens 的旋轉角度。
5. 將辨識結果回傳給控制程式。

例如：

```text
辨識結果：

X = 125.35 mm
Y =  82.60 mm
θ =   1.25°
```

注意：這是教學用數值。實際 Camera 一開始取得的是像素座標，不是直接得到機械平台的毫米座標。

## 四、為什麼 Camera 需要校正（Calibration）？

這是非常重要的觀念。

Camera 拍到的是像素（Pixel）。

但是運動控制系統使用的是毫米（mm）或角度（°）。

例如：

```text
Camera 影像：

Lens 中心
X = 1200 pixel
Y = 800 pixel
```

運動控制器需要的是：

```text
機械座標：

X = 12.5 mm
Y = 8.2 mm
```

因此必須建立影像座標與機械座標之間的對應關係。

這個過程稱為 Camera Calibration。

簡化理解：

```text
Camera 影像座標
       │
       ▼
   影像辨識
       │
       ▼
   找到中心點
       │
       ▼
   座標轉換
       │
       ▼
   機械座標
       │
       ▼
   六軸運動控制
```

如果沒有正確校正，即使 Camera 找到了 Lens 中心，也不一定能讓六軸正確移動到該位置。

## 五、Camera 如何與六軸配合？

假設 Lens 的中心位置有偏差。

Camera 辨識後發現：

```text
X 偏移：+0.10 mm
Y 偏移：-0.05 mm
角度偏移：+0.20°
```

控制程式將這些誤差轉換成運動命令。

```text
             Camera
                │
                ▼
           PR 影像辨識
                │
                ▼
           計算位置誤差
                │
                ▼
          LabVIEW 接收結果
                │
                ▼
           運動控制器
                │
                ▼
           六軸平台微調
                │
                ▼
           再次確認位置
```

這個過程可能重複執行，直到位置誤差符合設定條件。

這就是影像辨識與精密運動控制的結合。

## 六、對照你同事的週報

你之前提供的週報有幾個重要項目：

| 週報項目 | 與本課的關係 |
|---|---|
| CCD1~4 相機鏡頭調整 | Camera 光學配置 |
| Lens PR | 辨識 Lens |
| FAU PR | 辨識 FAU |
| PD PR | 辨識 Photodiode |
| Rx 影像辨識位置修正 | 修正接收端影像辨識位置 |
| 相機辨識功能完成 | 影像辨識功能 |
| AA | 後續主動光學對位 |

這代表 Camera 不只是提供畫面，而是整個精密對位流程的重要輸入來源。

不過，CCD1~4 各自負責什麼、使用什麼影像辨識演算法，仍需要實際設備文件或 LabVIEW 程式才能確認。

---

# 本課小測驗

**第 1 題**

Camera 拍到 Lens 後，PR 最重要的工作是什麼？

A. 控制伺服馬達。  
B. 找到 Lens 的特徵、中心位置與角度。  
C. 控制 UV 光。

**第 2 題**

為什麼 Camera 需要 Calibration？

A. 將影像像素座標與實際機械座標建立對應關係。  
B. 讓 Camera 拍照速度變快。  
C. 讓 Lens 自動旋轉。

**第 3 題**

Camera 已經辨識出 Lens 的中心位置，但是六軸還沒有移動。下一個合理的工作是什麼？

A. 直接啟動 UV 固化。  
B. 將辨識結果轉換成機械座標與位置誤差，再交給運動控制系統。  
C. 關閉 Camera。

**第 4 題**

六軸移動後，為什麼有時候還需要 Camera 再次拍照辨識？

A. 確認工件移動後的位置是否符合對位要求。  
B. 因為 Camera 必須一直拍照，不能停止。  
C. 因為 Camera 負責控制氣壓。

答完後進入第五課：**Tx/Rx、Power Meter 與 Active Alignment**。完成這一課，我們就正式開始 LabVIEW。


---

四題全部正確！很好！你已經理解 Camera 在設備中的角色：

**Camera 負責取得影像，PR 負責辨識位置，Calibration 負責座標轉換，六軸負責實際移動。**

這四個環節串起來，就是機器視覺對位的基本流程。

接下來是設備知識的最後一課。

# 第五課：Tx / Rx、Power Meter 與 Active Alignment

這一課要把前面學過的機構、六軸、Camera 串起來，了解 Dual Lens 設備究竟如何完成光學耦合（Optical Coupling）。

## 一、先認識 Tx 與 Rx

光通訊設備主要分成兩個方向：

| 名稱 | 英文 | 中文 | 功能 |
|---|---|---|---|
| Tx | Transmitter | 發射端 | 將電訊號轉換成光訊號 |
| Rx | Receiver | 接收端 | 將光訊號轉換成電訊號 |

可以想像成：

```text
             光訊號傳輸
┌────────┐                  ┌────────┐
│   Tx   │ ───────────────► │   Rx   │
│ 發射端 │       光         │ 接收端 │
└────────┘                  └────────┘
```

Tx 負責發光，Rx 負責接收光。

在光收發模組中，兩者可能整合在同一個模組內，但它們的功能不同。



## 二、Lens、FAU、PD 分別是什麼？

這幾個名稱在你同事的週報中反覆出現。

### 1. Lens（透鏡）

透鏡的作用是控制光線，例如聚焦、準直或改變光路。

在光通訊設備中，透鏡的位置和角度會影響光能量能否有效進入光纖或接收元件。

### 2. FAU（Fiber Array Unit）

FAU 是光纖陣列單元。

簡單理解：它將多條光纖依照一定的位置與間距排列固定。



### 3. PD（Photodiode）

PD 是光電二極體。

它可以將接收到的光轉換成電流訊號，供後續電路量測或處理。



簡化來看：

```text
Tx 發射端：

光源 → Lens → FAU → 光纖


Rx 接收端：

光纖 → FAU / Lens → PD
```

這是概念示意，實際光路會依產品設計而不同。

---

## 三、什麼是 Power Meter？

Power Meter 中文稱為光功率計。

它的工作是量測光訊號的功率。

例如：

```text
光源
 │
 ▼
Lens
 │
 ▼
光纖
 │
 ▼
Power Meter
 │
 ▼
顯示光功率
```

常見單位：

- mW：毫瓦。
- dBm：以 1 mW 為基準的對數功率單位。

例如：

| 光功率 | 意義 |
|---|---|
| 0 dBm | 1 mW |
| -3 dBm | 約 0.5 mW |
| -10 dBm | 0.1 mW |

注意：這些是光功率數值範例，不代表傳承設備的合格標準。

### 為什麼 Dual Lens 設備需要 Power Meter？

假設 Lens 和 FAU 之間沒有對準。

光線可能無法有效進入光纖，因此接收到的光功率會下降。

如果逐步調整 Lens 位置，並觀察 Power Meter 的讀值，就可以找到光耦合效果較好的位置。

這就是 Active Alignment 的重要基礎。

---

## 四、什麼是 Active Alignment（AA）？

這是整台設備最重要的工作之一。

Active Alignment 中文稱為主動對位。

它的核心概念是：

**一邊調整光學元件的位置，一邊實際量測光學訊號，找到最佳耦合位置。**

這與上一課的 Camera PR 有很大不同。

| 功能 | Camera PR | Active Alignment |
|---|---|---|
| 主要依據 | 影像特徵 | 實際光訊號 |
| 目的 | 找到物件位置 | 找到最佳光學耦合位置 |
| 使用設備 | Camera | 光源、Power Meter 等 |
| 調整方式 | 依影像位置修正 | 依光功率變化尋找最佳位置 |

### 用一個實際情境理解

假設 Lens 需要與 FAU 對準。

一開始的位置不一定是最佳位置。

設備可能會這樣運作：

**第一步：Camera PR**

Camera 找到 Lens 和 FAU 的位置。

```text
Camera
  │
  ▼
Lens PR + FAU PR
  │
  ▼
取得初始位置
```

**第二步：六軸移動**

根據辨識結果，讓 Lens 與 FAU 移動到初步對準的位置。

**第三步：啟動光學量測**

光源發出光，Power Meter 讀取光功率。

**第四步：微調位置**

假設不同位置得到以下量測結果：

| X 位置 | 光功率 |
|---|---:|
| 10.000 mm | -12 dBm |
| 10.010 mm | -8 dBm |
| 10.020 mm | -5 dBm |
| 10.030 mm | -7 dBm |
| 10.040 mm | -11 dBm |

從這個例子可以看出，X = 10.020 mm 時，量測到的光功率最高。

因此，這個位置可能是較佳的耦合位置。

注意：這只是簡化的單軸示範。實際 AA 可能同時調整多個軸，也可能使用更複雜的搜尋演算法。



---

## 五、把整台 Dual Lens 設備串起來

現在把前面五課學過的知識整合。

假設設備要完成一次 Lens 與 FAU 的耦合：

```text
          Auto Load
              │
              ▼
       PCB / 工件進入工作站
              │
              ▼
          夾持固定
              │
              ▼
          Camera PR
              │
              ▼
       辨識 Lens / FAU
              │
              ▼
       六軸初步位置調整
              │
              ▼
        Active Alignment
              │
              ▼
        Power Meter 量測
              │
              ▼
        六軸微調位置
              │
              ▼
        確認光功率結果
              │
              ▼
           Dispense
              │
              ▼
            UV Curing
              │
              ▼
           製程完成
```

這是教學用的整體流程，不代表客戶設備實際程式的執行順序已經確認。

### Dispense 與 UV Curing 是什麼？

- **Dispense：** 點膠，將膠水塗佈在指定位置。
- **UV Curing：** 使用紫外線照射，使 UV 膠固化，固定已完成對位的光學元件。

這也對應你同事週報中提到的：

- Tx AA
- Dispense
- UV

以及 GMT Dual Lens 設備公開規格中的雙點膠機構與 UV 固化設備。

---

# 六、LabVIEW 在這個流程中扮演什麼角色？

現在終於可以把設備與 LabVIEW 連接起來了。

LabVIEW 可能負責協調：

| 設備 | 可能的通訊方式 | LabVIEW 工作 |
|---|---|---|
| Camera | USB / GigE 等 | 取得影像、啟動 PR |
| 六軸控制器 | LAN / USB / 其他介面 | 下達移動命令、讀取軸狀態 |
| Power Meter | LAN / RS-232 / USB | 讀取光功率 |
| 點膠機 | RS-232 | 下達點膠命令 |
| UV 設備 | RS-232 或其他介面 | 控制 UV 固化 |
| 氣壓機構 | PLC / DI / DO | 控制夾持、送料等動作 |

這張表是依週報與一般設備架構整理的可能配置，實際通訊介面仍須查看 IPC 設定及 LabVIEW 程式。

你現在應該能理解：

LabVIEW 並不是直接負責所有機械動作，而是負責協調各個設備，判斷流程是否能繼續執行。

---

# 本課小測驗

最後四題，完成後我們就正式進入 LabVIEW。

**第 1 題**

Tx 和 Rx 的主要差異是什麼？

A. Tx 接收光，Rx 發射光。  
B. Tx 發射光，Rx 接收光。  
C. 兩者都是量測光功率。

**第 2 題**

Power Meter 在 Active Alignment 中主要負責什麼？

A. 量測光功率，讓系統知道目前的光耦合效果。  
B. 控制六軸馬達。  
C. 辨識 Lens 的中心位置。

**第 3 題**

Camera PR 已經找到 Lens 和 FAU 的初始位置，為什麼還需要 Active Alignment？

A. 因為 Camera 不能拍照。  
B. 因為幾何位置對準不代表光學耦合效果一定最佳，需要實際量測光訊號並微調。  
C. 因為 Power Meter 可以取代 Camera。

**第 4 題**

Active Alignment 找到較佳光學耦合位置後，為什麼還需要 Dispense 和 UV Curing？

A. 將已對準的光學元件固定，避免位置改變。  
B. 讓 Camera 拍攝更清楚。  
C. 讓 Power Meter 的讀值歸零。

答完後，我們正式開始：

**第六課：LabVIEW 是什麼？與 C++ 有什麼不同？**

接下來會開始真正學習 LabVIEW 的程式架構、Front Panel、Block Diagram、迴圈與 Case Structure，並逐步連接到你未來要接手的傳承設備專案。


---

首先，第五課的四題也全部正確！恭喜完成設備知識的五堂入門課程。接下來就可以正式進入 LabVIEW。

你問的週報問題很值得先整理，因為這能幫助你了解：**未來接手 LabVIEW 專案時，哪些功能可能還需要修改、測試或除錯。**

以下依照你之前提供的同事週報整理。我會區分「明確尚未完成」、「曾經發生但已完成」以及「需要進一步確認」三種情況。

# 一、傳承 Tx/Rx Auto Load

這個區塊主要涉及發射端 Tx 與接收端 Rx 的自動化耦光流程。

| 項目 | 週報狀態 | 我的分析 |
|---|---|---|
| Tx AA | 待實際點膠測試 | 尚未完成實際製程驗證 |
| Rx RSSI | 讀取問題 | 接收端訊號強度資料取得仍有問題 |
| MPO 插入／拔出 | 程式已完成 | 程式完成，但不代表實機驗證全部完成 |
| Rx FAU 夾取 | 已列入流程 | 需確認實際測試狀態 |
| Rx FAU PR | 已列入流程 | 需確認辨識精度 |
| Rx PD PR | 已列入流程 | 需確認辨識精度 |
| Rx AA pos | 已列入流程 | 需確認實際對位結果 |
| Tx AA、Dispense、UV | 有列出完成日期 | 需確認實際測試與驗收結果 |

### 我認為值得注意的問題

**1. Rx RSSI 讀取問題**

這是比較明確的軟體或通訊問題。

RSSI 是接收訊號強度指標，設備需要取得這個數值，才能了解接收端目前的光訊號狀態。

但目前還不知道：
- RSSI 是從哪個硬體取得？
- 是透過 LAN、RS-232、I²C，還是其他介面？
- 是讀取失敗、數值錯誤，還是更新不正常？

這些都可能成為你未來需要追蹤的 LabVIEW 程式問題。

**2. Tx AA 待實際點膠測試**

這代表不能只確認 AA 找到最佳位置，還要確認點膠後是否會影響光學元件的位置，以及 UV 固化後耦合結果是否仍符合要求。

---

# 二、傳承 Dual Lens Auto Load

這個區塊與你未來可能接手的工作最有關係。

依照週報，許多硬體配置、六軸控制、Camera、IIC 及自動化流程已經完成。

但仍有以下問題。

| 項目 | 週報狀態 | 我的分析 |
|---|---|---|
| FAU 樣品有時跳脫 | 待處理 | 夾持機構或夾取流程穩定性問題 |
| MPO 插拔機構 | 待調整 | 機構動作與定位問題 |
| Rx 影像辨識位置 | 待修正 | Camera PR 或座標轉換可能需要調整 |
| Rx 耦光程序 | 待完成 | 尚未完成整個 Rx 耦光流程 |
| Tx 點位校正 | 尚待完成 | Rx 耦光程序的前置條件 |

### 這裡有三個值得特別關注的方向

**1. FAU 夾取不穩定**

這可能涉及：
- 夾爪位置是否正確。
- 夾持力量是否足夠。
- FAU 是否放置在正確位置。
- 夾取後是否有感測器確認。
- LabVIEW 是否正確判斷夾取完成。

這不一定是 LabVIEW 程式錯誤，也可能是機構、氣壓或感測器問題。

**2. Rx 影像辨識位置修正**

這與我們第四課學到的 Camera PR 直接相關。

可能需要檢查：
- Rx 的 PR 辨識位置是否正確。
- Camera Calibration 是否正確。
- 像素座標轉換成機械座標是否正確。
- 辨識結果是否正確傳給六軸控制器。

這是未來你接手 LabVIEW 時，我認為值得優先了解的項目。

**3. Rx 耦光程序尚未完成**

週報提到：

> Rx 耦光程序完成，待 Tx 點位校正為完成後可進行耦光。

這表示 Rx 的耦光工作受到 Tx 點位校正進度影響。

但我們目前還不知道 Tx 點位校正為什麼會影響 Rx 耦光，也不知道兩者是機構基準、光學座標還是製程順序上的關係。

這部分應該向同事確認，不能自行推定。

---

# 三、OFC Dual Lens

這個區塊也有不少待處理問題。

注意：OFC Dual Lens 不應直接與傳承 Dual Lens 當成同一台設備。

| 項目 | 週報狀態 | 我的分析 |
|---|---|---|
| 光源控制器 24V | 只能長亮，無法調整光量 | 光源控制功能異常 |
| Camera USB 線長度 | 不足 | 硬體配置問題 |
| Camera 校正 | 尚未完成 | 影像座標與實際機械座標的對應尚待校正 |
| GMT 程式角度軸 | 有時出現異常 | 運動控制穩定性問題 |
| 主機電源按鈕 | 未接出 | IPC 或設備電源操作配置未完成 |

其中我認為有兩項比較值得注意：

**1. Camera 尚未校正**

這會直接影響 PR 辨識結果與運動控制之間的座標轉換。

即使 Camera 能夠正確辨識 Lens，也不代表六軸能夠正確移動到目標位置。

**2. 角度軸偶爾異常**

這可能涉及：
- 角度軸驅動器狀態。
- 運動控制命令。
- 位置回授。
- 軟體錯誤處理。
- 機構干涉。

需要進一步查看錯誤訊息及程式紀錄，才能判斷原因。

---

# 四、哪些問題已經完成，不應再當成待處理？

這也很重要，避免你接手時重複調查已經解決的問題。

依照週報，以下項目有明確完成紀錄：

| 項目 | 週報紀錄 |
|---|---|
| 六軸兩軸直線軸無訊號 | 已排除 |
| 六軸驅動器驗證 | 已完成 |
| 左手第六軸型號錯誤造成干涉 | 7/2 完成 |
| 雙六軸安裝與理線 | 7/17 完成 |
| 雙六軸軟體配置及測試 | 已完成 |
| 單軸移動、絕對位置移動 | 已測試 |
| 回原點、停止、緊急停止 | 已測試 |
| FDR、FLM、FRS、ERR 狀態 | 已測試 |
| ADC 數值確認 | 已完成 |
| CCD1~4 鏡頭調整 | 已完成 |
| 相機辨識功能 | 已完成 |
| IIC 讀取問題 | 已解決 |
| SLS-200 原廠修復 | 已完成 |
| ARCTAN 計算功能 | 已增加 |
| 自動化進料→工作→退料 | 已演示 |

提醒：週報上的「完成」是當時的紀錄，不等於現在已經確認所有功能仍正常。

---

# 五、我認為你接手 LabVIEW 時，最值得優先了解的五個問題

綜合整份週報，我會這樣排序：

| 優先順序 | 問題 | 為什麼值得優先了解 |
|---|---|---|
| 1 | Rx RSSI 讀取問題 | 涉及硬體通訊、資料讀取與錯誤處理 |
| 2 | Rx PR 影像辨識位置修正 | 涉及 Camera、影像辨識與座標轉換 |
| 3 | Rx 耦光程序 | 涉及完整的自動化流程 |
| 4 | FAU 偶爾跳脫 | 涉及夾爪、感測器及流程控制 |
| 5 | Tx 點膠及 UV 後的耦光驗證 | 涉及製程完成後的品質確認 |

這五項可以幫助你快速理解 LabVIEW 在實際設備中如何運作。

例如：

```text
LabVIEW
   │
   ├── 控制夾爪
   │
   ├── 啟動 Camera PR
   │
   ├── 讀取 RSSI
   │
   ├── 控制六軸
   │
   ├── 讀取 Power Meter
   │
   ├── 執行 AA
   │
   ├── 控制點膠機
   │
   └── 控制 UV
```

這就是你未來要理解的程式架構。

---

## 六、我建議你接下來怎麼學

我不建議再花很多時間學習其他設備原理。

目前已經具備足夠的基礎，可以進入 LabVIEW。

接下來我們應該採用這個順序：

1. LabVIEW 的基本概念。
2. Front Panel：操作介面。
3. Block Diagram：程式邏輯。
4. Dataflow：資料如何流動。
5. While Loop、Case Structure。
6. SubVI：如何拆分功能。
7. State Machine：如何管理整台設備的自動化流程。
8. RS-232、Ethernet、Camera、運動控制通訊。
9. 開始分析同事留下的 LabVIEW 專案。

**我特別希望你能理解 State Machine（狀態機）。**

因為你的設備有上料、夾取、PR、AA、點膠、UV、下料等步驟。這類自動化設備通常需要明確管理每個製程狀態、執行條件、完成條件及異常處理。

如果能理解 State Machine，你就比較容易看懂一套完整的設備控制程式。

下一步我們直接開始第六課：**LabVIEW 是什麼？與 C++ 有什麼不同？**

---

















