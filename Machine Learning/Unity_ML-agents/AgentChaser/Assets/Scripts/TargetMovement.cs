﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TargetMovement : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        transform.Translate(Input.GetAxis("Horizontal") * 20f * Time.deltaTime, 0, Input.GetAxis("Vertical") * 20f * Time.deltaTime);
    }
}
