'''
Created on 2018年3月21日

@author: 91934
'''
from selenium import webdriver
import csv
url = 'http://music.163.com/#/discover/playlist/?order=hot&cat=%E5%85%A8%E9%83%A8&limit=35&offset=0'

driver = webdriver.PhantomJS()

#准备好存储歌单的scv文件
csv_file = open("playlist.csv","w",newline = '')
writer = csv.writer(csv_file)
writer.writerow(['标题','播放数量','链接'])

#解析下一页直到'下一页为空'
while url != 'javascript:void(0)':
    # 加载页面
    driver.get(url)
    #切换到内容的iframe
    driver.switch_to.frame("contentFrame")
    # 定位歌单标签
    date = driver.find_element_by_id("m-pl-container").find_elements_by_tag_name("li")
    #解析一页中的所有歌单
    for i in range(len(date)):
        nb = date[i].find_element_by_class_name("nb").text
        if '万' in nb and int(nb.split("万")[0]) > 500:
            msk = date[i].find_element_by_css_selector("a.msk")
            writer.writerow([msk.get_attribute('title'),nb,msk.get_attribute('href')])
    
    # 定位下一页的url
    url = driver.find_element_by_css_selector("a.zbtn.znxt").\
        get_attribute('href')
csv_file.close()        
