# CommentRemover
( ⚠数据无价 · 谨慎使用 )

源代码注释删除工具，一键删除各种源代码内的注释  


## 支持类型
( ✅支持 🚧开发中 )  
||文件类型|单行注释|多行注释|
|-|---|---|---|
|✅|`.c` `.cpp` `.java` `.js` `.swift` `.rs` `.go`|`// Comment`|`/* Comment */`|
|🚧|`.py`       |`# Comment`        |`''' Comment '''` ```""" Comment """```|
|🚧|`.php`      |`# Comment` `// Comment` |`/* Comment */`|
|🚧|`.rb`       |`# Comment`        |`=begin Comment =end`|
|🚧|`.html`     |`<!-- Comment -->` |`<!-- Comment -->`|
|🚧|`.css`      |`/* Comment */`    |`/* Comment */`|

## 使用方法
使用之前请务必备份源文件，以避免程序出现可能的🐛bug  
1. 下载后运行
2. 将程序放在源代码文件所在的文件夹，或手动输入文件地址
3. 将源代码备份完成后，按照提示运行程序