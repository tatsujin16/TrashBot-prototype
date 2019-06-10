#!/r/binen pvython 
#-*-coding:utf-8-*-

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

        if len(message.body['text']) > 0:
                text = message.body['text']
                print(len(message.body['text']))
        elif len(message.body['attachments'][0]['pretext']) > 0:
                text = message.body['attachments'][0]['pretext']
                print(len(message.body['attachments'][0]['pretext']))

        Open = 'ゴミ箱開け'
        o = decode(Open)
        Close1 = 'ゴミ箱閉じ'
        c1 = decode(Close1)
        Close2 = 'ゴミ箱閉め'
        c2 = decode(Close2)
        Straight1 = 'ゴミ箱前'
        s1 = decode(Straight1)
        Straight2 = 'ゴミ箱進'
        s2 = decode(Straight2)
        Back = 'ゴミ箱後'
        b = decode(Back)
        Right = 'ゴミ箱右'
        ri = decode(Right)
        Left = 'ゴミ箱左'
        le = decode(Left)
        ComeOpen = 'ゴミ箱こっち'
        co = decode(ComeOpen)
        GoClose1 = 'ゴミ箱戻'
        gc1 = decode(GoClose1)
        GoClose2 = 'ゴミ箱あっち'
        gc2 = decode(GoClose2)
        Timer1 = 'ゴミ箱タイマ'
        t1 = decode(Timer1)
        Timer2 = 'ゴミ箱往'
        t2 = decode(Timer2)
        Sensor = 'ゴミ箱センサ'
        se = decode(Sensor)

        print text
        print type(text)
        if c1 in text or c2 in text:
                pub.publish(0)
        elif o in text:
                pub.publish(1)
        elif s1 in text or s2 in text:
                pub.publish(2)
        elif b in text:
                pub.publish(3)
        elif ri in text:
                pub.publish(4)
        elif le in text:
                pub.publish(5)
        elif co in text:
                pub.publish(6)
        elif gc1 in text or gc2 in text:
                pub.publish(7)
        elif t1 in text or t2 in text:
                pub.publish(8)
        elif se in text:
                pub.publish(9)
        else:
                pass
        message.reply(text)

def decode(string):
        translate = string.decode('utf-8')
        return translate

def main():
        bot = Bot()
        bot.run()

if __name__ == "__main__":
        rospy.init_node('google')
        print('start slackbot')
        main()
