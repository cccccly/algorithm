'''
Created on 2018年3月25日

@author: 91934
'''
from bs4 import BeautifulSoup
import requests
import re
headers = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36'}
root_url = 'http://www.ccgp-jiangsu.gov.cn/cgxx/cjgg/'   #主网站
root_res = requests.get(root_url,headers = headers)
root_res.encoding = 'utf-8'
root_text = root_res.text
root_soup = BeautifulSoup(root_text,'lxml')

urls = []  #待爬取的网站列表
def get_url():
    tabline = root_soup.find('div',class_='tab tabline')
    for a in tabline.find_all('a')[1:]:
        url = root_url[:-1]+a['href'][1:]
        urls.append(url)

get_url()

urls1 = []

file = r'D:\Coding\Html\urls.txt'
def get_url1():
    for url in urls[1:]:
        res = requests.get(url,headers = headers)
        soup = BeautifulSoup(res.text,'lxml')
        fanye = soup.find('div',class_='fanye')
        page_num = str(fanye.get_text().split()[0])
        page_num = re.sub("\D","",page_num)
        for num in range(int(page_num)-1):
            print(num)
            if(num == 0):
                url_a = url+'index.html'
            else:
                url_a = url +'index_' + str(num) + '.html'
            
            res_a = requests.get(url_a,headers = headers)
            soup_a = BeautifulSoup(res_a.text,'lxml')
            list = soup_a.find('div',class_='list_right02')
            for a in list.find_all('a'):    
                urls1.append(url+ a['href'][1:])
                print(url[:-1]+ a['href'][1:])  
                with open(file,'a') as file_obj:
                    file_obj.write(url[:-1]+ a['href'][1:] + '\n')
get_url1()













