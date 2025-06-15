@echo off
chcp 65001
setlocal

set /p str=请输入提交信息：

git add .
git commit -m "%str%"
git push origin master

pause
