1.UEFIMalAnalysis是UEFI恶意代码检测程序。
2.除了UEFIFiles中的文件(efi文件在上传时已被删除，请联系本人)外，请勿移动或修改其它目录、文件。

3.一次UEFI恶意代码检测的使用流程：
3.00  与3.01 是针对有规则配置权限的用户的功能。程序启动时，已读入了上次已保存的规则，所以不必预先定义规则。
3.01: 勾选 "定义危险UEFI文件规则"，弹出登录界面，账号与密码分别为admin,uefiadmin,登录后，可以定义规则。
3.01：选择一组特征码函数，点击“添加”，程序在判断不存在该组特征函数的子集或超集存在的情况下，该组特征函数组成的规则被添加，并且有规则的汇集更新显示。
已有的规则可以删除或双击，可以清空，可以保存。
3.1：用户浏览(默认为从UEFIFiles文件夹中)读入待分析的UEFI文件，选择用户权限，点击“开始分析”，即弹出各个文件的分析进度条，还有总体分析进度显示。
3.2 ：分析完毕，在UEFI文件分析提示框中显示分析结果，包括各个文件对各条规则的分析情况，当已定义的规则中某个函数的特征码被找到时，会有相应的源代码显示，并作出已分析的文件是否为危险文件的结论, 当疑为危险文件时以红色突出显示。

4.为保证界面美观，建议选择最大化显示。
5.技术支持email:jiangzw@ihep.ac.cn

1. Brief introduction:
A program written in Qt 4.6 to detect UEFI malicious code statically. 

Two types rules are pre-defined,which are administrator type and normal users.
Each rule can be consist of the selection of set  "Strcpy,IpIoAddIp,IpIoRemoveIp,
NetBufCopy,AsciiStrCopy,NetStringToIp,SockClone,WriteUnaligned64".

Main code is in the mainwindows.cpp,and the hexadecimal conversion from efi file is finished in qhexedit_p.cpp;

UEFI files *.efi are attached in the directory of release/UEFIFiles.

Relative paper link is :http://www.cqvip.com/QK/91690X/201232/43856767.html

2.How to use
Import the file-dir to Qt creator 1.3+.


