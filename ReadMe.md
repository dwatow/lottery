# 說明
這是一個模擬樂透、威力彩的電腦選號的程式。

# 注意
此程式不保證中獎，但是中獎歡迎來信告知。

# 介面

##文字輸入

可選擇大樂透還是威力彩(兩者的取樣範圍、取樣數不同)，規則寫在介面上。

可選擇要投注幾組號碼

##按鈕

「我要中大獎」: 進行隨機取號碼，並顯示在UI上空白區塊

「確定」: 關閉程式

# 修改

## 預設使用「系統管理員執行」

設定 Visual Studio 專案檔

[Project]>[Properties]>[Linker]>[Manifest File]

設定UAC Execution Level: requireAdministrator

參考：http://mqjing.blogspot.tw/2008/12/blog-post.html