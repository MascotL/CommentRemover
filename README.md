# CommentRemover
简体中文 | English  

## 简介

<b>( ⚠数据无价 · 谨慎使用 )</b>  
源代码注释删除工具，一键删除各种源代码内的注释  
支持所有计算机常用高级语言的注释的移除  
无需配置任何环境，即点即用


## 支持

平台 - Windows  
||文件类型|单行注释|多行注释|
|---|---|---|---|
|✅|`.c` `.cpp` `.java` `.js`<br>`.swift` `.rs` `.go`|`// Comment`|`/* Comment */`|
|🚧|`.py`       |`# Comment`        |`''' Comment '''`<br>`""" Comment """`|
|🚧|`.php`      |`# Comment`<br>`// Comment` |`/* Comment */`|
|🚧|`.rb`       |`# Comment`        |`=begin Comment =end`|
|🚧|`.html`     |`<!-- Comment -->` |`<!-- Comment -->`|
|🚧|`.css`      |`/* Comment */`    |`/* Comment */`|

<i>🚧开发中</i>

## 示例
 - 修改前：
```c
    // main
    int main() {
        printf("Hello, World!"); 
        for (int i = 0; i < 10; i++) {       
            /*
            Cyclic bodies
            */
        }
        return 0;
    }
```
 - 修改后：
```c
    int main() {
        printf("Hello, World!"); 
        for (int i = 0; i < 10; i++) {       

        }
        return 0;
    }
```

## 使用

使用之前请务必备份源文件，  
以避免程序出现可能的🐛bug  
1. 将程序放在源代码文件所在的文件夹  
2. 运行程序
3. 输入 `-all` 对此文件夹使用受支持的文件执行操作
4. 或者直接输入文件路径对单个文件执行操作
