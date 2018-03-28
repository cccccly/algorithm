'''
Created on 2018年3月27日

@author: 91934
'''
from bs4 import BeautifulSoup
import requests

headers = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36'}
file_in = r'D:\Coding\Html\urls.txt'
file_out = r'D:\Coding\Html\test.txt'
with open(file_in,'r') as file_in_obj:
    for line in file_in_obj:
        url = line.strip()
        res = requests.get(url)
        res.encoding = 'utf-8'
           
        soup = BeautifulSoup(res.text,'lxml')
        div_detail_con = soup.find('div',class_='detail_con')
        
        soup2 = BeautifulSoup(str(div_detail_con),'lxml')
        
        with open(file_out, 'a',encoding = 'utf-8') as file_out_obj:
            file_out_obj.write(soup2.get_text("\n", strip=True))