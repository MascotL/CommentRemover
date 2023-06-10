# CommentRemover
[简体中文](./README.md) | English

## Introduction

> <b>( ⚠️ Data is invaluable · Use with caution )</b>  
A source code comment removal tool that removes comments from various source code files with a single click.  
Supports the removal of comments in common advanced programming languages.  
No need to configure any environment, ready to use with a simple click.

## Supported Languages

||File Type|Single-line Comment|Multi-line Comment|
|---|---|---|---|
|✅|`.c` `.cpp` `.java` `.js`<br>`.swift` `.rs` `.go`|`// Comment`|`/* Comment */`|
|🚧|`.py`       |`# Comment`        |`''' Comment '''`<br>`""" Comment """`|
|🚧|`.php`      |`# Comment`<br>`// Comment` |`/* Comment */`|
|🚧|`.rb`       |`# Comment`        |`=begin Comment =end`|
|🚧|`.html`     |`<!-- Comment -->` |`<!-- Comment -->`|
|🚧|`.css`      |`/* Comment */`    |`/* Comment */`|

<i>(🚧 Under development)</i>&nbsp;&nbsp;&nbsp;&nbsp;only supports Windows

## Example
 - Before modification:
```c
Copy code
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
 - After modification:
```c
Copy code
    int main() {
        printf("Hello, World!"); 
        for (int i = 0; i < 10; i++) {       

        }
        return 0;
    }
```

## Usage

> Please make sure to backup your source files before using the program,
>to avoid potential bugs in the program.

1. Place the program in the same folder as the source code files and run the program.
2. Enter -all to perform the supported file operations on the entire folder.
3. Alternatively, directly enter the file path to perform operations on a single file.