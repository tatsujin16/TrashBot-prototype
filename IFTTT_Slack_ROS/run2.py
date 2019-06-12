#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
import json

from std_msgs.msg import Int16
from slackbot.bot import Bot
from slackbot.bot import default_reply

@default_reply()
def default_func(message):
        pub = rospy.Publisher('/TrashBot', Int16, queue_size=1)
        r = rospy.Rate(5)
        r.sleep()
        data = []
        if len(message.body['text']) > 0:
                text = message.body['text']
        elif len(message.body['attachments'][0]['pretext']) > 0:
                text = message.body['attachments'][0]['pretext']
        T = text.encode('utf-8')
        f = open('data.txt','r')
        #num_line = len (readlines()
        for line in f:
                line = line.strip()
                line = line.replace('\n','')
                line = line.split(",")
                data.append(line)
        f.close()
        for num1 in range(8):
                for num2 in range(8):
                        try:
                                A = data[num1][num2]
                                if A in T:
                                        pub.publish(num1)
                        except:
                                pass
        print('finish')
        message.reply(text)

def main():
        bot = Bot()
        bot.run()
        
if __name__ == "__main__":
        rospy.init_node('google')
        print('start slackbot')
        main()
