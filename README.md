# DES encode/decode plugin for Qt
![image](https://github.com/3014203030/images/blob/master/锁.png?raw=true)
#### Works on
- Qt 5.9 +
- Test on QtCreator 5.9.7  
- Debug with Qt_5_9_7_clang_64bit

#### Platforms
- Windows
- Linux
- Mac

#### API
- QString DES_encode(QString data, QString key);
> data: the text you want to encode
> key: the key you use for encoding (no matter length)

- QString DES_decode(QString data, QString key);
> data: the text you want to decode
> key: the key you use for decoding (no matter length)

#### Tips
> You can use checkBox to control whether the result should be decode or incode using base64.

#### Screenshot
- MainWindow
![image](https://github.com/3014203030/images/blob/master/JSDES.png?raw=true)
- Encode example
![image](https://github.com/3014203030/images/blob/master/JSDES_encode.png?raw=true)
- Decode example
![image](https://github.com/3014203030/images/blob/master/JSDES_decode.png.png?raw=true)
