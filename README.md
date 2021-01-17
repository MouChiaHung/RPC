# RPC using cpp and android binder mechanism

1. Copy cpp folder to  ${RepoTop}/external and run mm.

2. Run adb pull amos and amoc which are two executive files usually generated to $<{RepoTop}/out/target/product/system/bin/ after mm.

3. Run adb push amos and amoc to an Android phone.

4. Create two shells to execute them particularly.

5. Create one shell to run adb logcat to see their communication.

![image](https://github.com/MouChiaHung/RPC/blob/master/demo.jpg)
