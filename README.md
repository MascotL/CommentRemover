# CommentRemover
简体中文 | English  

## 简介

<b>( ⚠数据无价 · 谨慎使用 )</b>  
源代码注释删除工具，一键删除各种源代码内的注释  
支持所有计算机常用高级语言的注释的移除  
无需配置任何环境，即点即用


## 支持

( ✅支持 🚧开发中 )  
||文件类型|单行注释|多行注释|
|---|---|---|---|
|✅|`.c` `.cpp` `.java` `.js`<br>`.swift` `.rs` `.go`|`// Comment`|`/* Comment */`|
|🚧|`.py`       |`# Comment`        |`''' Comment '''`<br>`""" Comment """`|
|🚧|`.php`      |`# Comment`<br>`// Comment` |`/* Comment */`|
|🚧|`.rb`       |`# Comment`        |`=begin Comment =end`|
|🚧|`.html`     |`<!-- Comment -->` |`<!-- Comment -->`|
|🚧|`.css`      |`/* Comment */`    |`/* Comment */`|

## 示例

<div style="display: flex;">
  <div style="flex: 50%; padding-right: 10px;">
    <pre>修改前：
    <code>
    <span style="color: #7f848e;">// main</span>
    <span style="color: #c678dd;">int</span> <span style="color: #61afef;">main</span><span style="color: #d19a5e;">() {</span>
        <span style="color: #61afef;">printf</span><span style="color: #c678dd;">(</span><span style="color: #98c37a;">"Hello, World!"</span><span style="color: #c678dd;">)</span>; 
        <span style="color: #c678dd;">for (int </span>i <span style="color: #c678dd;">=</span> <span style="color: #d19a5e;">0</span>; i <span style="color: #c678dd;"><</span> <span style="color: #d19a5e;">10</span>; i<span style="color: #c678dd;">++) {       
            <span style="color: #7f848e;">/*
            Cyclic bodies
            */</span>
        }
        return </span><span style="color: #d19a5e;">0</span>;
    <span style="color: #d19a5e;">}</span>
    </code></pre>
  </div>
  <div style="flex: 50%; padding-left: 10px;">
    <pre>修改后：
    <code>
    <br>
    <span style="color: #c678dd;">int</span> <span style="color: #61afef;">main</span><span style="color: #d19a5e;">() {</span>
        <span style="color: #61afef;">printf</span><span style="color: #c678dd;">(</span><span style="color: #98c37a;">"Hello, World!"</span><span style="color: #c678dd;">)</span>; 
        <span style="color: #c678dd;">for (int </span>i <span style="color: #c678dd;">=</span> <span style="color: #d19a5e;">0</span>; i <span style="color: #c678dd;"><</span> <span style="color: #d19a5e;">10</span>; i<span style="color: #c678dd;">++) {       
            <br>
            <br>
        }
        return </span><span style="color: #d19a5e;">0</span>;
    <span style="color: #d19a5e;">}</span>
    <br>
    </code></pre>
  </div>
  <div style="flex: 50%; padding-left: 10px;">
    </code></pre>
  </div>
</div>

## 使用

使用之前请务必备份源文件，  
以避免程序出现可能的🐛bug  
1. 将程序放在源代码文件所在的文件夹  
2. 运行程序
3. 输入 `-all` 对此文件夹使用受支持的文件执行操作
4. 或者直接输入文件路径对单个文件执行操作
