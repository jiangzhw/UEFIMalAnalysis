1.UEFIMalAnalysis��UEFI������������
2.����UEFIFiles�е��ļ�(efi�ļ����ϴ�ʱ�ѱ�ɾ��������ϵ����)�⣬�����ƶ����޸�����Ŀ¼���ļ���

3.һ��UEFI����������ʹ�����̣�
3.00  ��3.01 ������й�������Ȩ�޵��û��Ĺ��ܡ���������ʱ���Ѷ������ϴ��ѱ���Ĺ������Բ���Ԥ�ȶ������
3.01: ��ѡ "����Σ��UEFI�ļ�����"��������¼���棬�˺�������ֱ�Ϊadmin,uefiadmin,��¼�󣬿��Զ������
3.01��ѡ��һ�������뺯�����������ӡ����������жϲ����ڸ��������������Ӽ��򳬼����ڵ�����£���������������ɵĹ�����ӣ������й���Ļ㼯������ʾ��
���еĹ������ɾ����˫����������գ����Ա��档
3.1���û����(Ĭ��Ϊ��UEFIFiles�ļ�����)�����������UEFI�ļ���ѡ���û�Ȩ�ޣ��������ʼ�������������������ļ��ķ����������������������������ʾ��
3.2 ��������ϣ���UEFI�ļ�������ʾ������ʾ������������������ļ��Ը�������ķ�����������Ѷ���Ĺ�����ĳ�������������뱻�ҵ�ʱ��������Ӧ��Դ������ʾ���������ѷ������ļ��Ƿ�ΪΣ���ļ��Ľ���, ����ΪΣ���ļ�ʱ�Ժ�ɫͻ����ʾ��

4.Ϊ��֤�������ۣ�����ѡ�������ʾ��
5.����֧��email:jiangzw@ihep.ac.cn

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


