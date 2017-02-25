# interview-microscene
interview for microscene

问题描述：

三维空间中可以用v(x,y,z）三维向量定位一个点，现存在N个点，针对这些坐标点数据集合做如下操作


计算出包含全部N个点的最小立方体（立方体边与三轴平行或垂直，下同）

(v_min,v_max) =（v_min,y_min,z_min,x_max,y_max,z_max）= model.GetBound(V)

给定任意空间点v_0 = (x0,y0,z0）和数量X，检索出距离v_0最近的X个空间点的坐标

V_near = (v1,...,vx) = model.GetNearBy(v_0,X)

给定任意空间范围 b = （v_min，v_max)检索出包含在这个空间范围内的空间点坐标 V_in = model.GetContained(b)

v_min = (x_min,y_min,z_min)

说明：

可以使用C或C++设计数据结构，可以使用任何工具库实现代码逻辑

写清楚编译过程，确保code可以运行

空间点数据文件data.txt，共计3列，空格分割，各列依次为 x、y、z，例如：  -1.674160 -10.792100 -8.642460 

代码提交到您个人的git账户，发送链接地址给面试官即可

需注意data.txt数据集合较大时的查询性能
