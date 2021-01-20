#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov  1 14:51:54 2019

@author: vicky
"""

import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd

# Main Function
"""
G = nx.barbell_graph(5,0)
c = girvan(G)
for i in c:
  print(i.nodes())
  print('---------')
nx.draw(G,with_labels=1)
plt.show()
"""
dataset = pd.read_csv('jharkhand_nodes.csv')
data_array = dataset.iloc[:].values
G = nx.Graph()
n = set([])
for i in range (len(data_array)):
  n.add(data_array[i][0])
  n.add(data_array[i][1])
for i in n:
  G.add_node(i)
for i in range(len(data_array)):
    G.add_edge(data_array[i][0],data_array[i][1])

nx.draw(G,with_labels=1)
plt.show()

