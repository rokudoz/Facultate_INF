import schedule
import time
import os
import sys
from datetime import datetime
import subprocess

serverList = {}

serverListFile = open("lista- servere-web.txt", "r")    

for serverIP in serverListFile:
    serverIP = serverIP.rstrip("\n")
    server = {serverIP : "unknown"}
    serverList.update(server)    

serverListFile.close()


print("==========================================")

def logPing(returncode, server):
    now = datetime.now()
    current_time = now.strftime("%H:%M")   

    if returncode == 0:
        if(serverList[server] == "unknown"):
            serverList[server] = "activ"
            print (server, 'este ACTIV la ora', current_time)

        elif(serverList[server] != "activ"):                
            serverList[server] = "activ"
            print (server, 'a devenit ACTIV la ora', current_time)
    else:
        if(serverList[server] == "unknown"):
            serverList[server] = "inactiv"
            print (server, 'este INACTIV la ora',current_time)
        elif(serverList[server] != "inactiv"):            
            serverList[server] = "inactiv"
            print (server, 'a devenit INACTIV la ora',current_time)


def executePings():    
    for server in serverList:
        proc = subprocess.Popen( ['ping', '-n', '1', server], stdout = subprocess.DEVNULL)
        proc.wait()
        logPing(proc.returncode,server)
        

executePings()
print("==========================================")

schedule.every(300).seconds.do(executePings)

while 1:
  schedule.run_pending()
  time.sleep(1)
